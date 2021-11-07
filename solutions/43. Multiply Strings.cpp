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
    
    // Community solution
    //https://leetcode.com/problems/multiply-strings/discuss/1563507/C%2B%2B-Simple-Easy-and-Short-Solution-Brief-Explanation
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        vector<int> res(num1.size()+num2.size(), 0);
        
        for (int i = num1.size()-1; i >= 0; i--) {
            for (int j = num2.size()-1; j >= 0; j--) {
                res[i + j + 1] += (num1[i]-'0') * (num2[j]-'0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }
        
        int i = 0;
        string ans = "";
        while (res[i] == 0) i++;
        while (i < res.size()) ans += to_string(res[i++]);
        
        return ans;
    }
​
};
