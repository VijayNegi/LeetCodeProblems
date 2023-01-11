class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,false);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]); 
            adj[e[1]].push_back(e[0]); 
        }
        int pathlen = dfs(n,0,adj,hasApple,visited)-2;
        return pathlen>0?pathlen:0;
    }
    int dfs(int n,int node,vector<vector<int>>& adj, vector<bool>& hasApple,vector<bool>& visited){
        if(node>=n) return 0;
        int paths=0;
        visited[node]= true;
        for(auto& child:adj[node]){
            if(!visited[child])
                paths += dfs(n,child,adj,hasApple,visited);
        }
        if(hasApple[node] || paths)
            paths+=2;
        return paths;
    }
};
