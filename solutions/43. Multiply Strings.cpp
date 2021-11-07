class Solution {
public:
    string multiply(string num1, string num2) {
        
        function<string(string,string)> bigAdd = [&](string num1,string num2)
        {
            int size1 = num1.size();
            int size2 = num2.size();
            string result;
            int carry(0);
            while( size1 && size2)
            {
                int num = (num1[size1-1] - '0') + (num2[size2-1]- '0') + carry;
                carry = num/10;
                num %=10;
                result.push_back(num + '0');
                --size1,--size2;
            }
            while( size1)
            {
                int num = (num1[size1-1] - '0') + carry;
                carry = num/10;
                num %=10;
                result.push_back(num + '0');
                --size1;
            }
            while( size2)
            {
                int num = (num2[size2-1] - '0') + carry;
                carry = num/10;
                num %=10;
                result.push_back(num + '0');
                --size2;
            }
            
            if(carry>0)
                result.push_back(carry + '0');
            reverse(result.begin(),result.end());
            return result;
        };
        
        
        function<string(string,string)> bigMul = [&](string num1,string num2)
        {
            int s1 = num1.size();
            int s2 = num2.size();
            string res;
            for(int i = s1-1 ; i>= 0; --i)
            {
                string temp;
                int carry(0);
                temp.append(s1 - i -1,'0');
                for(int j = s2-1; j>=0; --j)
                {
                    int num = (num1[i] - '0') * (num2[j] - '0') + carry;
                    carry = num/10;
                    num %=10;
                    temp.push_back(num + '0');
                }
                if(carry>0)
                    temp.push_back(carry + '0');
                reverse(temp.begin(), temp.end());
                res = bigAdd(temp,res);
            }
            return res;
        };
        if (num1 == "0" || num2 =="0")
            return "0";
        return bigMul(num1,num2);
    }
};
