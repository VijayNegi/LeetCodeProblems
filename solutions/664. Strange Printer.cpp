class Solution {
public:
    //my top down; WA
    int strangePrinter1(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector(n,0));
        
        function<int(int,int)> dfs = [&](int l,int r)
        {
            if(l>r) return 0;
            if(l==r) return 1;
            if(dp[l][r])
                return dp[l][r];
            
            if(s[l] != s[r])
            {
                // print start char all at once
                int k = r;
                while(k>l && s[k]!= s[l])
                    --k;
                dp[l][r] = dfs(l,k) + dfs(k+1,r);
                
                // print just curr sequence
                k = l;
                while(k<r && s[k]== s[l])
                    ++k;
                dp[l][r] = min(dp[l][r], 1 + dfs(k,r));
                
                
                return dp[l][r];
            }
            else
            {
                int ll=l,rr =r;
                while(ll<r && s[l] == s[ll])
                    ++ll;
                while(rr>l && s[r] == s[rr])
                    --rr;
                // print first and last
                if(ll>rr)
                {
                    dp[l][r] = 1;
                }
                else
                {
                    dp[l][r] = 1 + dfs(ll,rr);
                }
                
                // print unmatched sequence
                ll=l,rr;
                int count = 0;
                while(ll<r)
                {
                    if(s[ll]==s[l])
                        ++ll;
                    else
                    {
                        rr=ll;
                        while(s[rr]!=s[l])
                            ++rr;
                        count += dfs(ll,rr-1);
                        ll = rr;
                    }
                }
                dp[l][r] = min(dp[l][r], 1+count);
                
                // print just curr sequence
                int k = l;
                while(k<r && s[k]== s[l])
                    ++k;
                dp[l][r] = min(dp[l][r], 1 + dfs(k,r));
                
                return dp[l][r];
               
            }
            cout<<"invalid Path"<<endl;
            return 0;
               
        };
        
        return dfs(0,n-1);
    }
    // bottom up and make it symatric(i.e. printing continuous one or may does not make any diff)
    int strangePrinter2(string s) {
        int n = s.size();
        string p{s[0]};
        for(int i=1;i<n;++i)
            if(s[i]!=s[i-1])
                p.push_back(s[i]);
        s= p;
        n = s.size();
        vector<vector<int>> dp(n,vector(n,0));
        for(int i=0;i<n;++i)
            dp[i][i] = 1;
         
         for(int len=1;len<=n;++len)
         {
             for(int start = 0;start < n-len;++start)
             {
                 int end = start + len;
                 dp[start][end] = len +1;
                 for(int k=start;k<end;++k)
                 {
                     int sub = (s[k] == s[end])?1:0;
                      dp[start][end]= min(dp[start][end],dp[start][k]+ dp[k+1][end] - sub);
                 }
             }
         }
        
        return dp[0][n-1];
    }
    // top down : with above approach 
    int strangePrinter(std::string s)
    {   
        int n = s.size();
        vector<vector<int>> f(n,vector(n,0));
        
        function<int(int,int)> dfs = [&]( int l, int r)
        {
            if (l > r) return 0;
            if (f[l][r]) return f[l][r];
            f[l][r] = dfs(l, r - 1) + 1;
            for (int i = l; i < r; ++i)
            {
                if (s[i] == s[r])
                {
                    f[l][r] = std::min(f[l][r], dfs(l, i) + dfs(i + 1, r - 1));
                }
            }
            return f[l][r];
        };

        return dfs( 0, n - 1);
    }
    
    
    
    
};
