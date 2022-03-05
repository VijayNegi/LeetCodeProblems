const int mod = 1e9 +7;
class Solution {
    vector<vector<vector<int>>> dp;
public:
    // seems like prefix1 and digit_dp is not working while 
    // prefix2 and digit_dp2 is working fine, only changes is KMP algo
    int findGoodStrings(int n, string s1, string s2, string evil) {
        auto pi = prefix(evil);
        dp = vector(501,vector(51,vector(2,-1)));
        long counts1 = digit_dp(s1,0,evil,0,1,pi);
        //cout<<"-----"<<endl;
        dp = vector(501,vector(51,vector(2,-1)));
        long counts2 = digit_dp(s2,0,evil,0,1,pi);
        
        //counts1 = counts1%mod;
        //counts2 = counts2%mod;
        if(s1.find(evil) == string::npos) // as s1 was included in counts1
            ++counts2;
        //cout<<counts1<<" "<<counts2<<endl;
        return (counts2 - counts1 + mod)%mod;
    }
    
    int digit_dp(string& s1,int pos,string& s2,int pos2, bool res, vector<int>& pi)
    {
        //cout<<pos<<endl;
        if(pos2>=s2.size())
               return 0;;
        if(pos >= s1.size())
            return 1;
        if(dp[pos][pos2][res] != -1)
            return dp[pos][pos2][res];
        
        int limit = 'z';
        int count=0;
        if(res)
            limit = s1[pos];
        for(int i='a';i<=limit;++i)
        {
            int k = pos2;
            bool tres = res && (i==limit);
            while(k>0 && (i != s2[k]))
                k = pi[k-1];
            if(i == s2[k])
                ++k;
           
            if(k>=s2.size())
               continue;
            
            count += digit_dp(s1,pos+1,s2,k,tres,pi);
            count = count%mod;
        }
        
        return dp[pos][pos2][res] = count;
    }
    
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
            pi[k] = k;
        }
        return pi;
    }
    vector<int> prefix2(string s) {
        int n = s.size();
        vector<int> pi(n + 1, 0);
        pi[0] = -1;
        int k = -1;
              
        for (int i = 0; i < n; i++) {
            while(k >= 0 && s[k] != s[i]) 
                k = pi[k];
            pi[i+1] = ++k;
        }
        
        return pi;
    }
    int digit_dp2(string& s1,int pos,string& s2,int pos2, bool res, vector<int>& pi)
    {
        //cout<<pos<<endl;
        if(pos2>=s2.size())
               return 0;;
        if(pos >= s1.size())
            return 1;
        if(dp[pos][pos2][res] != -1)
            return dp[pos][pos2][res];
        
        int limit = 'z';
        int count=0;
        if(res)
            limit = s1[pos];
        for(int i='a';i<=limit;++i)
        {
            int k = pos2;
            bool tres = res && (i==limit);
            while(k>=0 && (i != s2[k]))
                k = pi[k];
            
            ++k;
            if(k==s2.size())
               continue;
            
            count += digit_dp2(s1,pos+1,s2,k,tres,pi);
            count = count%mod;
        }
        
        return dp[pos][pos2][res] = count;
    }
};
