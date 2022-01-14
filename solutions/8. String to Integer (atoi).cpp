class Solution {
public:
    int myAtoi1(string s) {
        long num=0;
        bool neg = false;
        int digits = 0;
        for(auto& c:s)
        {
            if(digits==0 && isspace(c)  )
                continue;
            else if(digits==0 && ( c=='-' || c=='+') )
            {
                if(c=='-')
                    neg = true;
                ++digits;
                continue;
            }
            else if(!isdigit(c))
                break;
                
            ++digits;
            num *=10;
            num += c-'0';
            if(num > (long)INT_MAX +1)
                break;
        }
        if(neg)
            num *= -1;
        
        if(num < INT_MIN)
            return INT_MIN;
        if(num > INT_MAX)
            return INT_MAX;
        return num;
    }
    // much cleaner
    int myAtoi(string s) {
        int sign = 1, base = 0, i = 0;
        while (s[i] == ' ') { i++; }
        if (s[i] == '-' || s[i] == '+') {
            sign = 1 - 2 * (s[i++] == '-'); 
        }
        while (s[i] >= '0' && s[i] <= '9') {
            if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && s[i] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            base  = 10 * base + (s[i++] - '0');
        }
        return base * sign;
    }
};
