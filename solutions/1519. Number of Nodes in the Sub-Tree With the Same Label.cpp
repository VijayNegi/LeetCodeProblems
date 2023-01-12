class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,false);
        vector<int> result(n,0);
        function<vector<int>(int)> dfs = [&](int node){
            visited[node]= true;
            vector<int> map(26,0);
            map[labels[node]-'a']++;
            for(auto& e:adj[node]){
                if(!visited[e]){
                    auto v = dfs(e);
                    for(int i=0;i<26;++i){
                        map[i] += v[i];
                    }
                }
            }
            result[node] = map[labels[node]-'a'];
            return map;
        };
        dfs(0);
        return result;
    }
};
