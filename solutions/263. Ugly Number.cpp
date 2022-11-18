class Solution {
public:
    bool isUgly1(int n) {
        if(n<=0)
            return false;
        while(n%2==0)
            n/=2;
        while(n%3==0)
            n/=3;
        while(n%5==0)
            n/=5;
        return n==1;
    }
    bool isUgly(int n) {
        if (n <= 0) return false;
        while (!(n % 3)) {
            n /= 3;
        }
        while (!(n % 5)) {
            n /= 5;
        }
        // No need for a third while loop
        return (n & (n - 1)) == 0;
    }
};
