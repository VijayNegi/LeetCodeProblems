class Solution {
public:
    vector<int> prefix(string s)
    {
        int n = s.size();
        int k=0;
        vector<int> pi(n,0);
        for(int i=1;i<n;++i)
        {
            while(k>0 && s[i]!=s[k])
                k = pi[k-1];
            if(s[i]==s[k])
                ++k;
            pi[i]=k;
        }
        return pi;
    }
    string shortestPalindrome(string s) {
        int n = s.size(),k=0;
        string sr = s;
        reverse(sr.begin(),sr.end());
        vector<int> p = prefix(s);
        for(int i=0;i<n;++i)
        {
            while(k>0 && sr[i]!= s[k])
                k = p[k-1];
            if(sr[i]==s[k])
                ++k;
        }
        return sr.substr(0,n-k) + s;
    }
};
