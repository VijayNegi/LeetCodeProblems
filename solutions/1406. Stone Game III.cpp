class Solution {
public:
    // self
    string stoneGameIII1(vector<int>& sv) {
        int n = sv.size();
        vector<int> sum(n+1,0);
        vector<int> dp(n+1,INT_MIN);
        dp[n]=0;
        for(int i=n-1;i>=0;--i){
            sum[i] = sv[i] + sum[i+1];
                int ss=0;
                for(int j=i;j<min(i+3,n) ;++j){
                    ss += sv[j];
​
                    dp[i] = max(dp[i],ss+ sum[j+1] - dp[j+1]);
                }
​
        }
        if(sum[0] == 2*dp[0]) return "Tie";
        return sum[0] > 2*dp[0] ? "Bob":"Alice";
    }
    // official solution
    // Note here dp is difference between the score
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = stoneValue[i] - dp[i + 1];
            if (i + 2 <= n) {
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
            }
            if (i + 3 <= n) {
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
            }
        }
        if (dp[0] > 0) {
            return "Alice";
        }
        if (dp[0] < 0) {
            return "Bob";
        }
        return "Tie";
    }
​
};
