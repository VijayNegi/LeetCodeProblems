class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = start ^ goal;
        int result =0;
        while(res)
        {
            ++result;
            res = res & (res-1);
        }
        return result;
    }
};
