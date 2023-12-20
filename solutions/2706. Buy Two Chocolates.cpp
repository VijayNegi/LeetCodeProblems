class Solution {
public:
    int buyChoco1(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int minCost = prices[0] + prices[1];
​
        if (minCost <= money) {
            return money - minCost;
        }
        return money;
    }
    int buyChoco(vector<int>& prices, int money) {
        int minimum = min(prices[0], prices[1]);
        int secondMinimum = max(prices[0], prices[1]);
        for (int i = 2; i < prices.size(); i++) {
            if (prices[i] < minimum) {
                secondMinimum = minimum;
                minimum = prices[i];
            } else if (prices[i] < secondMinimum) {
                secondMinimum = prices[i];
            }
        }
        int minCost = minimum + secondMinimum;
        if (minCost <= money)
            return money - minCost;
        return money;
    }
};
