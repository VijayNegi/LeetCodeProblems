class Solution {
public:
    string longestPalindrome(string s) {
        int len=0;
        int n = s.size();
        string result;
        for(int i=0;i<n;++i) {
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]) --l,++r;
            if(r-l-1>len) {
                len = r-l-1;
                result = s.substr(l+1,len);
            }
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]) --l,++r;
            if(r-l-1>len) {
                len = r-l-1;
                result = s.substr(l+1,len);
            }
        }
        return result;
    }
    string longestPalindrome(string s) {
        string temp;
        for(auto& c:s)
            temp+= c + '#';
        temp[temp.size()-1] = '^';
        temp = "$" + temp;
        
    }
    vector<int> manacher_odd(string& s) {
        int n = s.size();
        string t = "$"+s+"^";
        vector<int> p(n+2);
        int l = 1, r = 1;
        for(int i=1;i<=n;++i) {
            p[i] = max(0,min(r-i,p[l+(r-i)]));
            while(s[i-p[i]] == s[i+p[i]])
                ++p[i];
            if(i+p[i]>r) {
                 l = i - p[i], r = i + p[i];
            }
        }
         return vector<int>(begin(p) + 1, end(p) - 1);
    }
};
