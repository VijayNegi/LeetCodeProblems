class Solution {
public:
    // space m*n
    int uniquePaths1(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,1));
        
        for(int i=1;i!=m;++i)
        {
            for(int j=1;j!=n;++j)
               dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
        
        return dp[m-1][n-1];
    }
    //space 2*n
    int uniquePaths2(int m, int n) {
        vector<int> pre(n,1);
        vector<int> curr(n,1);
        
        for(int i=1;i!=m;++i)
        {
            for(int j=1;j!=n;++j)
            {
                curr[j] = pre[j] + curr[j-1];
            }
            swap(curr,pre);
        }
        
        return pre[n-1];
    }
    //space n
    int uniquePaths(int m, int n) {
        vector<int> curr(n,1);
        
        for(int i=1;i!=m;++i)
        {
            for(int j=1;j!=n;++j)
                curr[j] += curr[j-1];
        }
        
        return curr[n-1];
    }
};
