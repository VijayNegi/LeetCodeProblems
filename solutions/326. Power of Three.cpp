class Solution {
public:
    bool isPowerOfThree1(int n) {
        if(n<=0)
            return false;
        int k=1;
        while(k<=n) {
            if(k==n)
                return true;
            k *=3;
        }
        return false;
    }
    bool isPowerOfThree2(int n) {
        if(n<1)
            return false;
        
        while(n%3==0) {
           n/=3;
        }
        return n==1;
    }
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
​
