class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> visited(n,0);
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
        }
        int result = 0;
        int counter=2;
        vector<vector<int>> fcolor(n,vector<int>(26,0));
        function<int(int)> dfs = [&](int node){
            if(visited[node]==counter) return -1;
            if(visited[node]) return fcolor[node][colors[node]-'a'];
            visited[node] = counter;
            if(adj[node].size()){
                for(auto& nbr: adj[node]){
                    int res = dfs(nbr);
                    if(res<0) return res;
                    for(int i=0;i<26;++i)
                        fcolor[node][i] = max(fcolor[node][i],fcolor[nbr][i]);
                }
            }
            visited[node]--;
            return ++fcolor[node][colors[node]-'a'];
        };
        
        for(int i=0;i<n;++i){
            int res = dfs(i);
            if(res<0) return -1;
            result = max(res,result);
            ++counter;
        }
        return result;
    }
};
