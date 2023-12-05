class Solution {
public:
    int numberOfMatches1(int n) {
        int res = 0;
        while(n>1){
            res += n/2;
            n = (n+1)/2;
        }
        return res;
    }
    // elimination
    int numberOfMatches(int n) {
        return n-1;
    }
};
