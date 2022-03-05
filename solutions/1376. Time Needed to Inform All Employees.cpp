class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        
        for(int i=0;i<n;++i)
        {
            if(i!=headID)
                adj[manager[i]].push_back(i);
        }
        function<int(int)> dfs = [&](int i)
        {
            int time = 0;
            for(auto c: adj[i])
                time = max(time, dfs(c));
                
            if(adj[i].size())
                time += informTime[i];
            return time;
        };
        return dfs(headID);
    }
};
