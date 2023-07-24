class Solution {
public:
    double myPow(double x, long n) {
        if(n<0)
        {
            return 1.0/myPow(x,-n);
        }
        double res = 1; 
        while (n > 0) 
        { 
            if (n & 1) 
                res = res * x; 
            x = x * x; 
            n >>= 1; 
        } 
        return res;
    }
};
