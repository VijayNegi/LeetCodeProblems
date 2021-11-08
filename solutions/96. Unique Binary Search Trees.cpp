class Solution {
public:
    // dp - Memoization
    int numTrees1(int n) {
        vector<int> mem(n+2,0);
        mem[0] = 1;
        mem[1] = 1;
        mem[2] = 2;
        function<int(int)> uniqueBST = [&](int s)
        {
            if(mem[s]>0)
                return mem[s];
            
            int ways=0;
            for(int i=1;i<=s; ++i)
            {
                int left = uniqueBST(i-1);
                int right = uniqueBST(s-i);
                ways += left * right;
            }
            mem[s] = ways;
            return ways;
        };
        return uniqueBST(n);
    }
    // dp - Tabulation
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++) 
            for(int j = 1; j <= i; j++)
                dp[i] += dp[j-1] * dp[i-j];
        return dp[n];
    }
​
};
