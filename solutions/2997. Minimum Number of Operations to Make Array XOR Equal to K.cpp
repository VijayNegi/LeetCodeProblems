class Solution {
public:
     int minOperations1(vector<int>& A, int k) {
        for (int a : A)
            k ^= a;
        return __builtin_popcount(k);
    }
    int minOperations(vector<int>& n, unsigned int k) 
    {
        return popcount(reduce(begin(n), end(n), k, bit_xor<>()));
    }
    int minOperations2(vector<int>& A, unsigned int k) 
    {
        for (int x: A) {
            k ^= x;
        }
        int res = 0;
        while (k > 0) {
            res += (k & 1);
            k >>= 1;
        }
        return res;
    }
};
