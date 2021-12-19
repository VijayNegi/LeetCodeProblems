class Solution {
public:
    string decodeString(string s) {
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
                int x = getint(i);
                if(x>0)
                {
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
                    ++i;    // skip ]
                    break;
                }
                    
            }
            return t;
        };
        
        res = substr();
        return res;
    }
};
