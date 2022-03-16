class Solution {
public:
    int numDecodings1(string s) {
        vector<int> dp(s.size()+1,-1);
        return numdp(s,0,dp);
    }
    int numdp(string& s,int i,vector<int>& dp)
    {
        int n = s.size();
        if(i==n) return 1;
        if(s[i]=='0') return 0; // no number can start from 0
        if(i== n-1) return 1;
        if(dp[i]!=-1) return dp[i];
        
        int res = numdp(s,i+1,dp);
        if( i < n-1 && ( s[i] =='1' || (s[i]=='2' && s[i+1]<'7')))
           res += numdp(s,i+2,dp);
        
        return dp[i] = res;
    }
    //https://leetcode.com/problems/decode-ways/discuss/30451/Evolve-from-recursion-to-dp
    // dp with constant memory
    int numDecodings(string s) {
        int p = 1, pp, n = s.size();
        for(int i=n-1;i>=0;i--) {
            int cur = s[i]=='0' ? 0 : p;
            if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) cur+=pp;
            pp = p;
            p = cur;
        }
        return s.empty()? 0 : p;   
    }
    
    
};
