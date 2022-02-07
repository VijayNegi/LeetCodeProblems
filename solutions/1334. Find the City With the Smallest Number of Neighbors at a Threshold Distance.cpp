class Solution {
public:
    // Floyd warshell
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dp(n,vector(n,INT_MAX));
        
        for(int i=0;i<n;++i)
            dp[i][i] = 0;
        
        for(auto e:edges)
        {
            int v1=e[0],v2=e[1],dist=e[2];
            dp[v1][v2] = dist;
            dp[v2][v1] = dist;
        }
        
        for(int k=0;k<n;++k)
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j)
                {
                    if(dp[i][k]==INT_MAX || dp[k][j]==INT_MAX)
                        continue;
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
                                   
        int reachable = INT_MAX;
        int city = -1;
        
        for(int i=0;i<n;++i)
        {
            int count(0);
            for(int j=0;j<n;++j)
                if(dp[i][j]<=distanceThreshold)
                    ++count;
            if(count<=reachable)
            {
                reachable = count;
                city = i;
            }
        }
        return city;
            
    }
};
