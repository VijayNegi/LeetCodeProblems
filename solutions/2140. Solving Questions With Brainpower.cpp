class Solution {
public:
    long long mostPoints1(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long> dp(n,-1);
        function<long(int)> dfs = [&](int i)-> long {
            if(i>=n) return 0;
            if(dp[i]!=-1) return dp[i];
            dp[i] = max(dfs(i+1+questions[i][1])+ questions[i][0],dfs(i+1) );
            return dp[i];
        };
        return dfs(0);
    }
    // Iterative
     long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long> dp(n,0);
        dp[n - 1] = questions[n - 1][0];
        
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = questions[i][0];
            int skip = questions[i][1];
            if (i + skip + 1 < n) {
                dp[i] += dp[i + skip + 1];
            }
            
            // dp[i] = max(solve it, skip it)
            dp[i] = max(dp[i], dp[i + 1]);
        }
        
        return dp[0];
    }
};
