class Solution {
public:
    // Tarjans algorithm
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // build adjacency list
        vector<vector<int>> adj(n);
        for(auto c: connections)
        {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        int t=0;
        vector<int> id(n,-1), low(n,-1);
        vector<vector<int>> critical;
        function<void(int,int)> dfs_targen = [&](int v,int parent)
        {
            if(id[v]>=0)
                return;
            id[v] = t++;
            low[v] = id[v];
            for(auto n: adj[v])
            {
                if(n==parent)
                    continue;
                dfs_targen(n,v);
                
                low[v] = min(low[v],low[n]);
                if(id[v] < low[n])     // important as child was never able to reach back i.e. new SSC and count it ( no back link )
                    critical.push_back({v,n});
            }
        };
​
        dfs_targen(0,-1);
        return critical;
    }
};
