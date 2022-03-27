class Solution {
public:
    string addStrings1(string num1, string num2) {
        reverse(begin(num1),end(num1));
        reverse(begin(num2),end(num2));
        string result;
        int i=0;
        int carry=0;
        while(i<num1.size() && i<num2.size())
        {
            int n = num1[i] + num2[i] - 2* '0' + carry;
            result += n%10 +'0';
            carry = n/10;
            ++i;
        }
        
        while(i<num1.size())
        {
            int n = num1[i] - '0' + carry;
            result += n%10 +'0';
            carry = n/10;
            ++i;
        }
        while(i<num2.size())
        {
            int n = num2[i] - '0' + carry;
            result += n%10+'0';
            carry = n/10;
            ++i;
        }
        if(carry)
            result += '0'+carry;
        reverse(begin(result),end(result));
        return result;
    }
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";
        while(i>=0 || j>=0 || carry){
            long sum = 0;
            if(i >= 0){sum += (num1[i] - '0');i--;}
            if(j >= 0){sum += (num2[j] - '0');j--;}
            sum += carry; 
            carry = sum / 10;
            sum = sum % 10;
            res +=  sum +'0';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
