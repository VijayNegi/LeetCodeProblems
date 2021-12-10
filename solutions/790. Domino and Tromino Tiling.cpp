typedef long long ll;
const int mod = 1e9+7;
class Solution {
public:
    int numTilings1(int n) {
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        vector<vector<int>> dp(n+1,vector<int>(3,0)); // complete, empty up, empty down
        
        dp[1] = {1,0,0};
        dp[2] = {2,1,1};
        
        for(int i = 3;i<=n;++i)
        {
            dp[i][0] = ((ll)dp[i-1][0] + dp[i-2][0] + dp[i-1][1] + dp[i-1][2])%mod;
            dp[i][1] = ((ll)dp[i-1][2] + dp[i-2][0])%mod;
            dp[i][2] = ((ll)dp[i-1][1] + dp[i-2][0])%mod;
        }
        
        return dp[n][0];
    }
    //space optimization as both incomplete tiles are equal
    int numTilings2(int n) {
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        vector<vector<int>> dp(n+1,vector<int>(2,0)); // complete, empty up, empty down
        
        dp[1] = {1,0};
        dp[2] = {2,1};
        
        for(int i = 3;i<=n;++i)
        {
            dp[i][0] = ((ll)dp[i-1][0] + dp[i-2][0] + 2 * dp[i-1][1])%mod;
            dp[i][1] = ((ll)dp[i-1][1] + dp[i-2][0])%mod;
            //dp[i][2] = ((ll)dp[i-1][1] + dp[i-2][0])%mod;
        }
        
        return dp[n][0];
    }
    //further space optimization
    //https://leetcode.com/problems/domino-and-tromino-tiling/discuss/116581/Detail-and-explanation-of-O(n)-solution-why-dpn2*dn-1%2Bdpn-3
    int numTilings(int n) {
        if(n<=2)
            return n;
        
        vector<int> dp(n+1,0); // complete
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3;i<=n;++i)
        {
            dp[i] = ((ll)dp[i-1] + dp[i-1] + dp[i-3])%mod;
        }
        
        return dp[n];
    }
};
