class Solution {
public:
    // recursive
    int minimumOneBitOperations1(int n) {
        if (n == 0) {
            return 0;
        }
        
        int k = 0;
        int curr = 1;
        while (curr * 2 <= n) {
            curr *= 2;
            k++;
        }
        
        return (1 << (k + 1)) - 1 - minimumOneBitOperations(n ^ curr);
    }
    // Iteration
    int minimumOneBitOperations2(int n) {
        int ans = 0;
        int k = 0;
        int mask = 1;
        
        while (mask <= n) {
            if ((n & mask) != 0) {
                ans = (1 << (k + 1)) - 1 - ans;
            }
            
            mask <<= 1;
            k++;
        }
        
        return ans;
    }
    // gray code
    int minimumOneBitOperations(int n) {
        int ans = n;
        ans ^= ans >> 16;
        ans ^= ans >> 8;
        ans ^= ans >> 4;
        ans ^= ans >> 2;
        ans ^= ans >> 1;
        return ans;
    }
};
