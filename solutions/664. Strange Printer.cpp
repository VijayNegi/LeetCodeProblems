            return dp[l][r][prev-'a'] = result;
        };
        
        return print(0,n-1, 'z'+1);
    }
    // top down :
    int strangePrinter2(std::string s)
    {   
        int n = s.size();
        vector<vector<int>> dp(n,vector(n,0));
        
        function<int(int,int)> dfs = [&]( int l, int r)
        {
            if (l > r) return 0;
            if (dp[l][r]) return dp[l][r];
            dp[l][r] = dfs(l, r - 1) + 1;
            for (int i = l; i < r; ++i)
            {
                if (s[i] == s[r])
                {
                    // why below code works ?
                    // assume count to print from l to i, for i char we printed it till r. 
                    // so cost of printing char i is already covered.
                    // so we only need to add count of i+1 to r-1
                    dp[l][r] = std::min(dp[l][r], dfs(l, i) + dfs(i + 1, r - 1));
                }
            }
            return dp[l][r];
        };
​
        return dfs( 0, n - 1);
    }
    // bottom up and make it symatric
    int strangePrinter(string s) {
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
    
};
// very good code with explanations
/*
