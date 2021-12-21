class Solution {
public:
    bool isPowerOfTwo1(int n) {
        int bitCount=0;
        while(n>0)
        {
            if(n & 1)
                ++bitCount;
            n = n>>1;
        }
        return bitCount==1;
    }
    
    bool isPowerOfTwo(int n) {
        
        return n>0 && !(n & n-1);
    }
    
    
    
};
