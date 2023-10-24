class Solution {
public:
    // cleaner solution
    string decodeString(const string& s, int& i) {
        string res;
        
        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';
                    
                i++; // '['
                string t = decodeString(s, i);
                i++; // ']'
                
                while (n-- > 0)
                    res += t;
            }
        }
        
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }

    // self
    string decodeString1(string s) {
        string res;
        string temp;
        int i=0;
        
        function<int(int&)> getint = [&](int& idx)
        {
            int x=0;
            while(idx < s.size() && s[idx] >='0' && s[idx]<= '9')
            {
                x *=10;
                x += s[idx] - '0';
                ++idx;
            }
            return x;
        };
        
        function<string(void)> substr = [&](){
            string t;
            while(i<s.size())
            {
                //cout<<"s[i] "<<s[i]<<endl;
                int x = getint(i);
                if(x>0)
                {
                    //cout<<"int="<<x<<endl;
                    ++i; // skip [
                    string s = substr();
                    while(x-- > 0)
                        t.append(s);  
                }
                else if(s[i]>='a' && s[i]<='z')
                {
                    t.append(1,s[i]);
                    ++i;               
                }
                else
                {
                    ++i;    // skip ]
                    break;
                }
                    
            }
            return t;
        };
        
        res = substr();
        return res;
    }
};
