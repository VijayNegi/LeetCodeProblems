class Solution {
public:
    // DP
    int maxProfit1(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> free(n, 0), hold(n, 0);
        
        // In order to hold a stock on day 0, we have no other choice but to buy it for prices[0].
        hold[0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            free[i] = max(free[i - 1], hold[i - 1] + prices[i] - fee);
            hold[i] = max(hold[i - 1], free[i - 1] - prices[i]);
        }
        
        return free[n - 1];
    }
    // space optimized
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int free = 0, hold = -prices[0];
        
        for (int i = 1; i < n; i++) {
            int tmp = hold;
            hold = max(hold, free - prices[i]);
            free = max(free, tmp + prices[i] - fee);
        }
        
        return free;
    }
};
