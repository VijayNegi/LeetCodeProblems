class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        for(int i=1;i<=amount;++i) {
            int k = INT_MAX;
            for(auto& c:coins) {
                if(i-c >=0 && dp[i-c]>=0)
                    k = min(k,dp[i-c]+1);
            }
            dp[i] = k!=INT_MAX ? k : -1;   
        }
        return dp[amount];
    }
};
