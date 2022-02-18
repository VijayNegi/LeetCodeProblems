class Solution {
public:
    // Eulerian Path and Hierholzer's algorithm.
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> inOutdegree;
        for(auto p:pairs)
        {
            adj[p[0]].push_back(p[1]);
            inOutdegree[p[0]]++;
            inOutdegree[p[1]]--;
        }
        int start=-1;
        for(auto it:inOutdegree)
        {
            if(it.second>0)
                start = it.first;
        }
        if(start==-1)
            start = pairs[0][0];
        
        vector<vector<int>> result;
        function<void(int)> dfs = [&](int node)
        {
            while(adj[node].size())
            {
                int next = adj[node].back();
                adj[node].pop_back();
                dfs(next);
                result.push_back({node,next});
            }
        };
        
        dfs(start);
        reverse(result.begin(),result.end());
        return result;
    }
};
