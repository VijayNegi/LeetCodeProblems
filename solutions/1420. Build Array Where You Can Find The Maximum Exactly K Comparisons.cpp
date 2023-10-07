const int mod = 1e9+7;
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n,vector(m+1,vector<int>(k+1,-1)));
        function<int(int,int,int)> dfs = [&](int i,int mmax,int remainingk) -> int {
            if(remainingk<0) return 0;
            if(i==n) return remainingk==0;
            if(dp[i][mmax][remainingk] != -1) return dp[i][mmax][remainingk];
            long result = dfs(i+1,mmax,remainingk);
            result *=mmax;
            result %=mod;
            for(int j=mmax+1;j<=m;++j){
                result += dfs(i+1,j,remainingk-1);
                result %=mod;
            }
            return dp[i][mmax][remainingk] = result;
        };
        return dfs(0,0,k);
    }
};
