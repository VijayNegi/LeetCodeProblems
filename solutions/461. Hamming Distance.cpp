class Solution {
public:
    //xor
    int hammingDistance1(int x, int y) {
        int z = x^y;
        int ans(0);
        for(int i=0; i!=32 && z ; ++i)
        {
            ans += z & 1;
            z = z>>1;
        }
        return ans;
        
    }
    // using bitset
    int hammingDistance2(int x, int y) {
        bitset<32> xb(x), yb(y);
        int ans = 0;
        for(int i = 0; i < 32; i++)
            ans += xb[i] != yb[i];
        return ans;
        
    }
    // xor and Brian-Kernighan
    int hammingDistance(int x, int y) {
        int Xor = x ^ y, ans = 0;
        while(Xor) 
            ans++,
            Xor &= Xor-1;
        return ans;
    }
​
};
