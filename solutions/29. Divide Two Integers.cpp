class Solution {
public:
    int divide1(int dividend, int divisor) {
        long result=0;
        bool sign = false;
        if(dividend<0) sign = !sign;
        if(divisor<0) sign = !sign;
        long dvd = abs(dividend*1.0);
        long dvr = abs(divisor*1.0);
        long d = dvr;
        long count=1;
        while(dvd >= d)
        {
            if(dvd >= d)
            {
                dvd -=d;
                result +=count;
                d <<=1;
                count<<=1;
            }
            if(d>dvd)
            {
                 d = dvr;
                count=1;
            }
        }
        result = sign? -1*result:result;
        if(result >INT_MAX) return INT_MAX;
        if(result < INT_MIN) return INT_MIN;
        return result;
    }
    // Not working now
    // https://leetcode.com/problems/divide-two-integers/discuss/142849/C%2B%2BJavaPython-Should-Not-Use-%22long%22-Int
    int divide2(int A, int B) {
        if (A == INT_MIN && B == -1) return INT_MAX;
        int a = abs(A), b = abs(B), res = 0, x = 0;
        while (a - b >= 0) {
            for (x = 0; a - (b << x << 1) >= 0; x++);
            res += 1 << x;
            a -= b << x;
        }
        return (A > 0) == (B > 0) ? res : -res;
    }
​
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};
