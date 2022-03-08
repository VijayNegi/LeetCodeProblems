const int mod = 1e9+7;
class Solution {
public:
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
​
