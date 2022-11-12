const int mod = 1e9+7;
class Solution {
public:
    int countGoodStrings1(int low, int high, int zero, int one) {
        int result = 0;
        vector<int> dp(high+1,0);
        dp[0]=1;
        for(int i=min(zero,one);i<=high;++i) {
            if(i>=zero) {
                dp[i] += dp[i-zero];
                dp[i] = dp[i]% mod;
            }
            if(i>=one){
                dp[i] += dp[i-one];
                dp[i] = dp[i]% mod;
            }
        }
        
        for(int i=low;i<=high;++i){
            result += dp[i];
            result = result%mod;
        }
        return result;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        dp[0] = 1;
        int res = 0, mod = 1e9 + 7;
        for (int i = 1; i <= high; ++i) {
            if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % mod;
            if (i >= one) dp[i] = (dp[i] + dp[i - one]) % mod;
            if (i >= low) res = (res + dp[i]) % mod;
        }
        return res;
    }
};
