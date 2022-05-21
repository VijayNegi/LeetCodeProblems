class Solution {
public:
    // self :4ms 
    bool checkPowersOfThree1(int n) {
        if(n==1)
            return true;
        int th = 1;
        int maxp = INT_MAX;
        while(n>0) {
            int p=0;
            while(th*3<=n) {
                th*=3;
                ++p;
            }
            if(p==maxp)
                break;
            n -=th;
            maxp=p;
            th=1;
        }
        return n==0; 
    }
    // maths
    // https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/discuss/1107040/C%2B%2B-Easiest-solution-with-detailed-explanation
    // https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/discuss/1100341/Convert-n-to-base-3
    bool checkPowersOfThree2(int n) {
        if(n==1)
            return true;
        if(n%3==2)
            return false;
        return checkPowersOfThree2(n/3);
    }
    // iterative : 0ms
    bool checkPowersOfThree(int n) {
    while (n > 0 && n % 3 != 2)
        n /= 3;
    return n == 0;
}
};
