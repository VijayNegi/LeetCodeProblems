// Read - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75924/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems
class Solution {
public:
    int maxProfit(vector<int>& p, int res = 0) {
      for (int i = 1; i < p.size(); ++i) res += max(0, p[i] - p[i - 1]);
      return res;
    }
    int maxProfit1(int k, vector<int>& prices) {
      if (k >= prices.size() / 2) return maxProfit(prices);
      vector<int> buys(k + 1, INT_MIN), sells(k + 1, 0);
      for (auto p : prices)
      {
        //cout<<endl<<"input- "<<p<<endl;
        for (auto i = 1; i <= k; ++i) {
          buys[i] = max(buys[i], sells[i - 1] - p);
          sells[i] = max(sells[i], buys[i] + p);  
            //cout<<buys[i]<<" "<<sells[i]<<" ";
        }
      }
      return sells[k];
    }
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/2555699/LeetCode-The-Hard-Way-7-Lines-or-Line-By-Line-Explanation
    int maxProfit(int k, vector<int>& prices) {
        // no transaction, no profit
        if (k == 0) return 0;
        // dp[k][0] = min cost you need to spend at most k transactions
        // dp[k][1] = max profit you can achieve at most k transactions
        vector<vector<int>> dp(k + 1, vector<int>(2));
        for (int i = 0; i <= k; i++) dp[i][0] = INT_MAX;
        for (auto& price : prices) {
            for (int i = 1; i <= k; i++) {
                // price - dp[i - 1][1] is how much you need to spend
                // i.e use the profit you earned from previous transaction to buy the stock
                // we want to minimize it
                dp[i][0] = min(dp[i][0], price - dp[i - 1][1]);
                // price - dp[i][0] is how much you can achieve from previous min cost
                // we want to maximize it
                dp[i][1] = max(dp[i][1], price - dp[i][0]);
            }
        }
        // return max profit at most k transactions
        // or you can use `return dp.back()[1];`
        return dp[k][1];
    }
    
};
