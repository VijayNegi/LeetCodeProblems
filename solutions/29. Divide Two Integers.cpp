        return (A > 0) == (B > 0) ? res : -res;
    }
​
    int divide3(int dividend, int divisor) {
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
    // official solution
    int divide(int dividend, int divisor) {
                if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        int negative = 2;
        if(dividend > 0)
        {
            dividend = -dividend;
            negative--;
        }
        
        if(divisor > 0)
        {
            divisor = -divisor;
            negative--;
        }
        
        int quotient = 0;
        
        vector<int> powOfTwos;
        vector<int> values;
        
        int powOfTwo = -1;
        int value = divisor;
        while(dividend <= value)
        {
            values.push_back(value);
            powOfTwos.push_back(powOfTwo);
            if (value < INT_MIN/2) {
                break;
            }
            value *= 2;
            powOfTwo *= 2;
        }
        
        for(int i=values.size()-1; i>=0;i--)
        {
            if(dividend <= values[i])
            {
                dividend -= values[i];
                quotient += powOfTwos[i];
            }
        }
        
        return (negative!= 1 ? -quotient: quotient);
    }
};
