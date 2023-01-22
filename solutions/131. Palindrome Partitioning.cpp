class Solution {
public:
    // 161
    vector<vector<string>> partition1(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        int n = s.size();
        function<void(int)> dfs = [&](int l){
            if(l==n ){
                result.push_back(curr);
            }
            for(int i=l;i<n;++i){
                if(palindrome(s,l,i)){
                    curr.push_back(s.substr(l,i-l+1));
                    dfs(i+1);
                    curr.pop_back();
                }
            }
        };
        dfs(0);
        return result;
    }
    bool palindrome(string str, int s,int e){
        while(s<=e)
            if(str[s++]!=str[e--]) return false;
        return true;
    }
        // dp
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n+1,vector<bool>(n+1,false));
        vector<vector<string>> result;
        
        vector<string> curr;
        function<void(int,int)> part = [&](int l,int h)
        {
            if(l>h)
            {
                result.push_back(curr);
                return;
            }
                
            for(int i=l;i<=h;++i)
            {
                if((s[l] == s[i]) && (i-l<2 || isPalindrome[l+1][i-1] ))//           isPalindrome(s,l,i-1))
                {
                    isPalindrome[l][i] = true;
                    curr.push_back(s.substr(l,i-l+1));
                    part(i+1,h);
                    curr.pop_back();
                }
         
            }
        };
        
        part(0,s.size()-1);
        return result;
    }
};
