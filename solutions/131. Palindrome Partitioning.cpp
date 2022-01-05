class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> result;
        
        function<bool(string&,int,int)> isPalindrome = [](string& s, int l,int h)
        {
            if(l>h)
                return false;
            while(l<=h && s[l]==s[h]) ++l,--h;
            return l>h;
        };
        
        vector<string> curr;
        function<void(int,int)> part = [&](int l,int h)
        {
           if(isPalindrome(s,l,h))
           {
               curr.push_back(s.substr(l,h-l+1));
               result.push_back(curr);
               curr.pop_back();
           }
            for(int i=l+1;i<=h;++i)
            {
                if(isPalindrome(s,l,i-1))
                {
                    curr.push_back(s.substr(l,i-l));
                    part(i,h);
                    curr.pop_back();
                }
         
            }
        };
        
        part(0,s.size()-1);
        return result;
    }
};
