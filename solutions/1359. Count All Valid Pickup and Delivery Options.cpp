const int mod = 1e9+7;
class Solution {
public:
    // self
    int countOrders0(int n) {
        vector<vector<int>> dp(n+1,vector(n+1,-1));
        function<int(int,int)> ways = [&](int p, int d){
            if(p==0 && d==0)
                return 1;
            if(dp[p][d] != -1) return dp[p][d];
            long val = 0;
            if(p>0){
                val = p*1l * ways(p-1,d+1);
                val %=mod;
            }
            if(d >0){
                val += d *1l* ways(p,d-1);
                val %=mod;
            }
            return dp[p][d] = val;
        };
        return ways(n,0);
    }
    int countOrders1(int n) {
        long result=1;
        
        // ways to put pickups:  n!
        for(int i=1;i<=n;++i)
        {
            result *= i;
            result %= mod;
        }
        // ways to put deliverys in backword order
        for(int i=1;i<=n;++i)
        {
            result *= (2*i-1)%mod;
            result %= mod;
        }
        return result;
    }
    // https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/discuss/516951/C%2B%2BJavaPython-Simple-Math-Formula-with-Explanation-Clean-and-Concise
    int countOrders2(int n) {
        long long MODULO = 1e9 + 7, ans = 1;
        for (int i = 2; i <= n; i++) {
            int spaceNum = (i-1)*2 + 1;
            ans *= spaceNum * (spaceNum + 1) / 2;
            ans %= MODULO;
        }
        return (int) ans;
    }
    // same post
    int countOrders(int n) {
        long long MODULO = 1e9 + 7, ans = 1;
        for (int i = 2; i <= n; i++) {
            int spaceNum = (i-1)*2 + 1;
            ans *= spaceNum * (spaceNum + 1) / 2;
            ans %= MODULO;
        }
        return (int) ans;
    }
};
