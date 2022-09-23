const int mod = 1e9+7;
class Solution {
public:
    // 94 ms
    int concatenatedBinary1(int n) {
        uint64_t sum=0;
        for(int i=1;i<=n;++i) {
            int k=i;
            while(k) {
                sum <<=1;
                k>>=1;
            }
            sum = sum | i;
            sum  = sum % mod;
        }
        return sum;
    }
    // 50 ms
    int concatenatedBinary(int n) {
        long ans = 0, len = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) ++len; // increase length if power of two
            ans = ((ans << len) % mod + i) % mod;
        }
        return ans;
    }
};
