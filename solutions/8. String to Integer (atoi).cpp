class Solution {
public:
    int myAtoi(string s) {
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
};
