class Solution {
public:
    // more generic code.
    vector<int> plusOne(vector<int>& digits) {
        reverse(begin(digits),end(digits));
        int carry = 1;
        for(auto& d: digits)
        {
            d = d+carry;
            carry = d/10;
            d = d%10;
            if(!carry)
                break;
        }
        if(carry)
            digits.push_back(1);
        reverse(begin(digits),end(digits));
        return digits;
    }
    // old one
    vector<int> plusOne1(vector<int>& digits) {
        if(digits.size()<1)
        {
            digits.push_back(1);
            return digits;
        }
          
        bool append(false);
        for(int i=digits.size()-1;i>=0;--i)
        {
            if(digits[i]<9)
            {
                ++digits[i];
                break;
            }
            else
            {
                digits[i]=0;
            }
        }
      
        if(digits[0]==0)
        {
            digits.push_back(0);
            digits[0]=1;
        }
        
        return digits;
    }
};
