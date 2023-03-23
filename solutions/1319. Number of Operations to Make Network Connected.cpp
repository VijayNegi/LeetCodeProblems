struct DSU{
    vector<int> parent;
    int sets;
    DSU(int _n):parent(_n,0),sets(_n){
        iota(begin(parent),end(parent),0);
    }
    int find(int idx){
        if(parent[idx] == idx) return idx;
        return parent[idx] = find(parent[idx]);
    }
    bool merge(int idx1,int idx2){
        int pid1 = find(idx1);
        int pid2 = find(idx2);
        if(pid1 == pid2) return false;
        parent[pid2] = pid1;
        --sets;
        return true;
    }
};
class Solution {
public:
    // self : Dsu
    int makeConnected1(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        DSU ds(n);
        int edges = 0;
        for(auto& v: connections){
            if(!ds.merge(v[0],v[1]))
                ++edges;
        }
        return ds.sets-1;
    }
    // dfs solution
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n - 1)
            return -1;
        vector<vector<int>> adj(n);
        for(auto v : connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        function<void(int)> dfs = [&](int src) {
            visited[src] = true;
            for(int i : adj[src])
                if(!visited[i])
                    dfs(i);
        };
        int components = 0;
        for(int i=0; i<n; i++)
            if(!visited[i]) {
                dfs(i);
                components++;
            }
        return components - 1;
    }
};
