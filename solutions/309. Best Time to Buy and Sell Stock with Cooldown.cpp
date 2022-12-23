class Solution {
public:
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75927/Share-my-thinking-process
    int maxProfit1(vector<int> &prices) {
        int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
        for (int price : prices) {
            prev_buy = buy;
            buy = max(prev_sell - price, buy);
            prev_sell = sell;
            sell = max(prev_buy + price, sell);
        }
        return sell;
    }
    //https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/761981/PythonGoJavaJSC%2B%2B-O(n)-by-DP-and-state-machine.-w-Visualization
    int maxProfit2(vector<int>& prices) {
        
        // initialization
        int coolDown=0, sell=0, hold=std::numeric_limits<int>::min();
        for( int stockPrice_Day_i : prices){
            int prevCoolDown = coolDown, prevSell = sell, prevHold = hold;
             // Max profit of cooldown on Day i comes from either cool down of Day_i-1, or sell out of Day_i-1 and today Day_i is cooling day
            coolDown = max(prevCoolDown, prevSell);
            // Max profit of sell on Day_i comes from hold of Day_i-1 and sell on Day_i
            sell = prevHold + stockPrice_Day_i;
            
            // Max profit of hold on Day_i comes from either hold of Day_i-1, or cool down on Day_i-1 and buy on Day_i
            hold = max(prevHold, prevCoolDown - stockPrice_Day_i);
        }
        
        // The state of max profit must be either sell or cool down
        return max( sell, coolDown );
    }
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
    int maxProfit(vector<int>& prices){
        if (prices.size() <= 1) return 0;
        vector<int> s0(prices.size(), 0);
        vector<int> s1(prices.size(), 0);
        vector<int> s2(prices.size(), 0);
        s1[0] = -prices[0];
        s0[0] = 0;
        s2[0] = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            s0[i] = max(s0[i - 1], s2[i - 1]);
            s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
            s2[i] = s1[i - 1] + prices[i];
        }
        return max(s0[prices.size() - 1], s2[prices.size() - 1]);
    }
};
