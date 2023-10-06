class Solution {
public:
    int integerBreak1(int n) {
        if (n <= 3) 
            return n - 1;
        int result=0;
        vector<int> dp(60,-1);
        function<int(int)> dfs = [&](int num){
            if(num<=3) return num;
            if(dp[num]!= -1) return dp[num];
            for(int i=2; i<=num/2;++i){
                dp[num] = max(i*max(num-i,dfs(num-i)),dp[num]);
            }
            return dp[num];
        };
        return dfs(n);
    }
    // maths solution: its optimal to break in 2's and 3's
    int integerBreak(int n) {
        if (n <= 3) 
            return n - 1;
        
        int ans = 1;
        while (n > 4) {
            ans *= 3;
            n -= 3;
        }
        
        return ans * n;
    }
};
