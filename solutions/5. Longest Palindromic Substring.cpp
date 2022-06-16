class Solution {
public:
    string longestPalindrome1(string s) {
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
    // manacher
    string longestPalindrome(string s) {
        int n = s.size();
        vector<int> d1(n,0);
        vector<int> d2(n,0);
        int i,l,r;
        // for odd centers
        for(i=0,l=0,r=-1;i<n;++i)
        {
            int k = (i>r)? 1: min(d1[l+r-i],r-i+1);
            while(i-k>=0 && i+k<n && s[i+k]==s[i-k])
                ++k;
            
            d1[i] = k--;
            
            if(i+k>r)
            {
                r = i+k;
                l = i-k;
            }
        }
        // for even centers
        for(i=0,l=0,r=-1;i<n;++i)
        {
            int k = (i>r)? 0: min(d2[l+r-i+1],r-i+1);
            while(i-k-1>=0 && i+k < n && s[i+k]==s[i-k-1])
                ++k;
            d2[i] = k--;
            
            if(i+k > r)
            {
                r = i+k;
                l = i-k-1;
            }
        }
        int maxLen = 0;
        string res;
        for(int i=0;i<n;++i)
        {
            if(2*d1[i]-1 > maxLen)
            {
                res = s.substr(i-d1[i]+1,2*d1[i]-1);
                maxLen = 2*d1[i]-1;
            }
            if( 2*d2[i] > maxLen)
            {
                res = s.substr(i-d2[i],2*d2[i]);
                maxLen = 2*d2[i];
            }
        }
        
        return res;
    }
};
