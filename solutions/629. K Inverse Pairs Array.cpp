const int mod = 1e9+7;
class Solution {
public:
    int kInversePairs1(int n, int k) {
        if(n==0)
            return 0;
        if(k==0)
            return 1;
        
        vector<int> curr(k+1,0),pre(k+1,0);
        for(int i=1;i<=n;++i) {
            for(int j=0;j<=k;++j) {
                if(j==0 )
                    curr[j]=1;
                else {
                    curr[j]=0;
                    for(int l=0;l<=min(i-1,j);++l) 
                        curr[j] = (curr[j] + pre[j-l])%mod;
                }
            }
            swap(curr,pre);
        }
        return pre[k];
    }
    // official solution
    int kInversePairs2(int n, int k) {
        vector<int> dp(k+1,0),temp(k+1,0);
        for (int i = 1; i <= n; i++) {
            temp[0] = 1;
            for (int j = 1; j <= k ; j++) {
                int val = (dp[j] + mod - ((j - i) >= 0 ? dp[j - i] : 0)) % mod;
                temp[j] = (temp[j - 1] + val) % mod;
            }
            swap(dp,temp);
        }
        return ((dp[k] + mod - (k > 0 ? dp[k - 1] : 0)) % mod);
    }
    // official solution
    int kInversePairs(int n, int k) {
        vector<int> dp(k+1,0),temp(k+1,0);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k && j <= i * (i - 1) / 2; j++) {
                if (i == 1 && j == 0) {
                    dp[j] = 1;
                    break;
                } else if (j == 0)
                    dp[j] = 1;
                else {
                    int val = (temp[j] + mod - ((j - i) >= 0 ? temp[j - i] : 0)) % mod;
                    dp[j] = (dp[j - 1] + val) % mod;
                }
            }
            swap(dp,temp);
        }
        return temp[k];
    }
};
