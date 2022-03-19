class Solution {
public:
    int minimumWhiteTiles1(string floor, int nC, int cLen) {
        int n = floor.size();
        if(nC*cLen>=n)
            return 0;
        
        vector<int> sw(n-cLen+1,0);
        int count=0;
        int white=0;
        for(int i=0;i<n;++i)
        {
            if(floor[i]=='1')
                ++count,++white;
            if(i==cLen-1)
                sw[i-cLen+1] = count;
            if(i>=cLen)
            {
                if(floor[i-cLen]=='1')
                    --count;
                sw[i-cLen+1] = count;
            }
        }
        int result = white;
        vector<vector<int>> dp(n+1,vector(nC+1,-1));
        function<int(int,int)> bt1 = [&](int pos,int remain)
        {
            if(pos>=n || remain==0)
                return 0 ;
             
             if(dp[pos][remain]!=-1)
                 return dp[pos][remain];
            int covered = max(sw[pos-cLen+1]+bt1(pos+cLen,remain-1), bt1(pos+1,remain));
            return dp[pos][remain] = covered;
        };
​
        int cov = bt1(cLen-1,nC);
        return white-cov;
    };
    // DP bottom up: 786ms
    //https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/discuss/1863955/JavaC%2B%2BPython-DP-solution
    int minimumWhiteTiles2(string s, int nc, int l) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(nc + 1));
        for (int i = 1; i <= n; ++i) {
            for (int k = 0; k <= nc; ++k) {
                int jump = dp[i - 1][k] + s[i - 1] - '0';  // count white tile if you skip this tile
                int cover = k > 0 ? dp[max(i - l, 0)][k - 1] : 1000; // if you place tile end at current tile
                dp[i][k] = min(cover, jump);
            }
        }
        return dp[n][nc];
    }
    
    // 1654 or sometime TLE
    // https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/discuss/1863872/Python-short-dp-explained
    int minimumWhiteTiles(string s, int nc, int l) {
        vector<vector<int>> mem(s.size()+1,vector(nc+1,-1));
        function<int(int,int)> dp = [&](int pos,int t)
        {
            if(t<0)             return INT_MAX;
            if(pos<0)           return 0;
            if(mem[pos][t]!=-1) return mem[pos][t];
            return mem[pos][t] = min(dp(pos-l,t-1),dp(pos-1,t)+ s[pos]-'0');
        };
        return dp(s.size()-1,nc);
    }
​
};
