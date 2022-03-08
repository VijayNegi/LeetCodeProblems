const int mod = 1e9+7;
class Solution {
public:
    int countOrders(int n) {
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
};
​
