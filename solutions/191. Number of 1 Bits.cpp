class Solution {
public:
    int hammingWeight1(uint32_t n) {
        int count=0;
        while(n)
        {
            if(n & 1)
                ++count;
            n = n>>1;
        }
        return count;
    }
    // only remove last set bit
    int hammingWeight(uint32_t n) {
        int count = 0;
​
        while (n) {
            n &= (n - 1);
            count++;
        }
​
        return count;
    }
};
