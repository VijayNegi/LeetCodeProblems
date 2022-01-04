class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = n | 1;
        int k = n;
        while(k)
        {
            mask = mask | (k-1);
            k = k & (k-1);
        }
        return mask & ~n;
    }
};
