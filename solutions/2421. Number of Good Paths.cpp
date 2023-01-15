        map<int, vector<int>> valuesToNodes;
        for (int node = 0; node < n; node++) {
            valuesToNodes[vals[node]].push_back(node);
        }
        DSU dsu(n,vals);
        int goodPaths = 0;
        for (auto& [value, nodes] : valuesToNodes) {
            for (int node : nodes) {
                for (int neighbor : adj[node]) {
                    if (vals[node] >= vals[neighbor]) {
                            dsu.merge(node, neighbor);
                    }
                }
            }
            unordered_map<int, int> group;
            for (int u : nodes) {
                group[dsu.find(u)]++;
            }
            for (auto& [_, size] : group) {
                goodPaths += (size * (size + 1) / 2);
            }
        }
        return goodPaths;
    }
    // DFS solution 123/134 tle
    int numberOfGoodPaths1(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_map<int,int> temp;
        map<int,int> path; // path with value; we need sorted
        for(auto& v:vals)
            temp[v]++;
        // for(auto& t:temp)
        //     if(t.second>1)
        //         path[t.first] = 0;
        
        
        int result = 0;
        vector<bool> visited(n,false);
        
        function<void(int, map<int,int>&)> dfs = [&](int node,map<int,int>& paths){
            auto it = paths.lower_bound(vals[node]);
            map<int,int> pathcopy(it,paths.end());
            //auto pathcopy = paths;
            // for(auto& p:pathcopy){
            //     if(p.first < vals[node])
            //         p.second = 0;
            //     else break;
            // }
            visited[node] = true;
