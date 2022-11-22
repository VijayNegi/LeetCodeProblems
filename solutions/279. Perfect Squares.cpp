class Solution {
    vector<int> dp;
public:
    int numSquares(int n) {
        dp.resize(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        return dfs(n);
    }
    int dfs(int n) {
        int i=1;
        if(dp[n]!=-1)
            return dp[n];
        int res=INT_MAX;
        while(i*i<=n){
            res = min(dfs(n-i*i),res);
            ++i;
        }
        return dp[n]= res+1;;
    }
};
