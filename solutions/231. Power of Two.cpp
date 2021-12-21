class Solution {
public:
    bool isPowerOfTwo(int n) {
        int bitCount=0;
        while(n>0)
        {
            if(n & 1)
                ++bitCount;
            n = n>>1;
        }
        return bitCount==1;
    }
};
