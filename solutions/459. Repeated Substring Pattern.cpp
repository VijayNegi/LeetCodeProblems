class Solution {
public:
    // KMP prefix function
    vector<int> prefix_function(string s)
    {
        int n = s.size();
        vector<int> pi(n,0);
        int k=0;
        for(int i=1;i<n;++i)
        {
            while(k>0 && s[k] != s[i])
                k = pi[k-1];
            if(s[k]==s[i])
                ++k;
            pi[i] = k;
        }
        return pi;
    }
    // 8 ms
     bool repeatedSubstringPattern1(string s) {
         int n = s.size();
         vector<int> pi = prefix_function(s);
         int patternLen = n- pi[n-1];
         if(patternLen==n || n%patternLen )
             return false;
​
         return true;
    }
    // 20 ms
    //https://leetcode.com/problems/repeated-substring-pattern/discuss/826135/C%2B%2B-O(N)-time-or-One-liner-without-KMP-Explained-or-Beats-99
    bool repeatedSubstringPattern(string s) {
        return (s + s).substr(1, 2*s.size()-2).find(s) != -1;
    }
};
