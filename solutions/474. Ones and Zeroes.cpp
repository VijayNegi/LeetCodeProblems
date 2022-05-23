class Solution {
public:
    // self : 497ms
    int findMaxForm1(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<pair<int,int>> c;
        for(auto& s:strs )
        {
            int ones = 0;
            int zeros = 0;
            for(auto c:s)
                (c=='0')?++zeros:++ones;
            c.push_back({zeros,ones});
        }
        vector<vector<vector<int>>> dp(l,vector(m+1,vector(n+1,-1)));
        
        function<int(int,int,int)> dfs = [&](int i,int m1,int n1) {
            if(i>=l)
                return 0;
            if(dp[i][m1][n1]!= -1)
                return dp[i][m1][n1];
            
            if(m1 >= c[i].first && n1 >= c[i].second)
                dp[i][m1][n1] = dfs(i+1,m1-c[i].first,n1-c[i].second) +1;
            dp[i][m1][n1] = max(dp[i][m1][n1], dfs(i+1,m1,n1));
            return dp[i][m1][n1];
        };
        return dfs(0,m,n);
    }
    // https://leetcode.com/problems/ones-and-zeroes/discuss/1138589/Short-and-Easy-w-Explanation-or-O(L*m*n)-DP-solution-(6-lines)-similar-to-knapsack
    // bottom up :
    int findMaxForm(vector<string>& strs, int m, int n) {
​
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        for(auto& str : strs) {           
            int zeros = count(begin(str), end(str), '0'), ones = size(str) - zeros; 
            // which positions of dp will be updated ?
            // Only those having atleast `zeros` 0s(i >= zeros) and `ones` 1s(j >= ones)
            for(int i = m; i >= zeros; i--)
                for(int j = n; j >= ones; j--)                    
                    dp[i][j] = max(dp[i][j], // either leave the current string
                                   dp[i - zeros][j - ones] + 1); // take it
          
        }
        return dp[m][n];
    }
};
