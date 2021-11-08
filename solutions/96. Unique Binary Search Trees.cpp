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
    int numTrees2(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++) 
            for(int j = 1; j <= i; j++)
                dp[i] += dp[j-1] * dp[i-j];
        return dp[n];
    }
    // catalan numbers
    long ncr(int n, int r) {
        long ans = 1;
        for(int i = 0; i < r; i++) {
            ans *= n-i;
            ans /= i+1;
        }
        return ans;   
    }
    int numTrees(int n) {
        return ncr(2*n, n) / (n + 1);
    }
​
};
