class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        int result = numeric_limits<int>::max();
        vector<vector<int>> dp(n1+1,vector(n2+1,-1));
        function<int(int,int)> dfs = [&](int i,int j){
            if(i==n1 && j==n2)
                return 0;
            if(dp[i][j] != -1) return dp[i][j];
            dp[i][j] = numeric_limits<int>::max();
            if(j == n2)
                return dp[i][j] = dfs(i+1,j) + s1[i];
             if(i == n1)
                return dp[i][j] = min(dp[i][j], dfs(i,j+1) + s2[j]);
            
            if(s1[i] == s2[j])
                dp[i][j] = min(dp[i][j],dfs(i+1,j+1));
            else{
                dp[i][j] = min(dp[i][j],dfs(i,j+1) + s2[j]);
                dp[i][j] = min(dp[i][j],dfs(i+1,j) + s1[i] );
            }
            
            
            return dp[i][j];
        };
        return dfs(0,0);
    }
};
