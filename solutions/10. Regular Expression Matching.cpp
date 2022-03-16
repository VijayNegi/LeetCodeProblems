class Solution {
public:
    bool isMatch2(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector(p.size()+1,-1));
        return isMatch1(0,s,0,p,dp);
        //return match(s,s.size()-1,p,p.size()-1,dp);
    }
    // mine , back to front, 0ms dp
    bool match(string& s,int si, string& p,int pi, vector<vector<int>>& dp)
    {
        //cout<<si<<" "<<pi<<endl;
        if(si==-1 && pi==-1)
            return true;
        if(pi==-1) // pattern could have redundent match so wait like a* at beginning
            return si==-1;
        if(dp[si+1][pi+1]!= -1)
            return dp[si+1][pi+1];
        if(p[pi]=='*')
        {
            if(match(s,si,p,pi-2,dp))
                return dp[si+1][pi+1] = true;
            while(si>=0 && (s[si]==p[pi-1] || p[pi-1]=='.'))
                if(match(s,--si,p,pi-2,dp))
                    return dp[si+1][pi+1] = true;
            return dp[si+1][pi+1] =false;
        }
        else if(si>=0)
        {
            if((s[si]==p[pi] || p[pi]=='.') && match(s,si-1,p,pi-1,dp) )
                return dp[si+1][pi+1] = true;
        }
        return dp[si+1][pi+1] = false;
    }
    
    // front to back dp
    bool isMatch1(int i, string& s, int j, string &p, vector<vector<int>> &dp) {
        if(dp[i][j] > -1) return dp[i][j];
        int pn=p.size(), sn = s.size();
        if(j==pn) return dp[i][j] = i==sn;
        if(p[j+1]=='*') {
            if(isMatch1(i,s,j+2,p,dp) || 
               i<sn && (p[j] == '.' || s[i] == p[j]) && isMatch1(i+1,s,j,p,dp)) 
               return dp[i][j] = 1;
        } else if (i<sn && (p[j]=='.'|| s[i]==p[j]) && isMatch1(i+1,s,j+1,p,dp)) 
            return dp[i][j] = 1;
        return dp[i][j] = 0;
    }
    // bottom up approach
    bool isMatch(string s, string p) {
        int pn=p.size(), sn = s.size();
        vector<vector<bool>> dp(sn+1,vector<bool>(pn+1));
        dp[sn][pn] = 1;
        for(int i = sn;i>=0;i--) 
            for(int j=pn-1;j>=0;j--) 
                if(p[j+1]=='*') 
                    dp[i][j] = dp[i][j+2] || i<sn && (p[j] == '.' || s[i] == p[j]) && dp[i+1][j];
                else dp[i][j] = i<sn && (p[j]=='.'|| s[i]==p[j]) && dp[i+1][j+1];
        return dp[0][0];    
    }
​
};
