class Solution {
public:
    // self, contest
    long long coloredCells1(int n) {
        long long result=1;
        for(int i=2;i<=n;++i)
            result += 4*(i-1);
        return result;
    }
    // self , sum of above series
    long long coloredCells(int n) {
        long long result=0;
        --n;
        result = 1ll *n*(n+1)/2; // sum of natural numbers
        return 1+result*4; // multiply by four
    }
    //https://leetcode.com/problems/count-total-number-of-colored-cells/discuss/3256196/JavaC%2B%2BPython-Cut-and-Combine-O(1)
    long long coloredCells2(int n) {
        return 1l * n * n + 1l * (n - 1) * (n - 1);
    }
    long long coloredCells3(int n) {
        return 2l * n * (n - 1) + 1;
    }
    // https://leetcode.com/problems/count-total-number-of-colored-cells/discuss/3256418/Sum-of-arithmetic-mean-oror-Very-Simple-and-Easy-to-understand-solution
    long long coloredCells4(int n) {
        if(n == 1) return 1;
        long long t  = n-1;
        return 1 + (t * (8 + (t-1)*4))/2;
    }
};
