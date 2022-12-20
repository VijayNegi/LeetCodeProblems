class Solution {
public:
    // can also be done with DSU
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
            
        vector<bool> visited(n,false);
        queue<int> nodes;
        nodes.push(source);
        while(nodes.size()){
            int node = nodes.front();
            nodes.pop();
            if(visited[node])
                continue;
            if(node == destination)
                return true;
            visited[node] = true;
            for(auto& nei:adj[node])
                if(!visited[nei])
                    nodes.push(nei);
        }
        return false;
    }
};
