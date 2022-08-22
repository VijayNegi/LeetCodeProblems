class Solution {
public:
    bool isPowerOfFour(int n) {
        long m=1;
        while(m<INT_MAX) {
            if(n==m)
                return true;
            m*=4;
        }
        return false;
    }
};
