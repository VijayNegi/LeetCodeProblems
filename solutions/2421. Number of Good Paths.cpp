struct DSU{
    vector<int> parent,value,count;
    int goodPoint;
    DSU(int n, vector<int> _value):parent(n,0),value(_value),count(n,1),goodPoint(0){
        iota(parent.begin(),parent.end(),0);
    }
    int find(int id){
        if(parent[id]==id) return id;
        return parent[id] = find(parent[id]);
    }
    void merge(int id1,int id2){
        int pid1 = find(id1);
        int pid2 = find(id2);
        if(pid1==pid2) return;
        if(value[pid1] < value[pid2]){
            parent[pid1] = pid2;
            //++goodPoint;
        }
        else if(value[pid1] > value[pid2]){
            parent[pid2] = pid1;
            //++goodPoint;
        }
        else {
            parent[pid1] = pid2;
            //goodPoint += count[pid1]*count[pid2];
            //count[pid1] += count[pid2];
        }
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
         int n = vals.size();
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
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
        //     if(t.second>1)
        //         path[t.first] = 0;
        
        
        int result = 0;
        vector<bool> visited(n,false);
        
        function<void(int, map<int,int>&)> dfs = [&](int node,map<int,int>& paths){
            auto it = paths.lower_bound(vals[node]);
            map<int,int> pathcopy(it,paths.end());
            //auto pathcopy = paths;
            // for(auto& p:pathcopy){
            //     if(p.first < vals[node])
            //         p.second = 0;
            //     else break;
            // }
            visited[node] = true;
            for(auto child:adj[node])
                if(!visited[child]){
                    dfs(child,pathcopy);
                    auto it = pathcopy.lower_bound(vals[node]);
                    
                    pathcopy.erase(pathcopy.begin(),it);
                    // for(auto& p:pathcopy){
                    //     if(p.first < vals[node])
                    //         p.second = 0;
                    //     else break;
                    // }
                }
            //cout<<node<<" = "<<pathcopy[vals[node]]<<endl;
            result += pathcopy[vals[node]];
            for(auto& p:pathcopy){
                if(p.second > paths[p.first])
                    paths[p.first] = p.second;
            }
            if(temp[vals[node]]>1)
                paths[vals[node]]++;
        };
        dfs(0,path);
        return result+n;
    }
};
