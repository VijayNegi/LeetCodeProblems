class Solution {
public:
    // finding vally then peak. 232 ms
    int maxProfit1(vector<int>& prices) {
        int maxp=0;
        int minseen = prices[0];
        
        for(auto p:prices)
        {
            maxp = max(maxp, p - minseen);
            minseen = min(minseen,p);
        }
        return maxp;
    }
    // adding single day profits, kadanes algo, 120 ms
    int maxProfit(vector<int>& prices) {
        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxCur = max(0, maxCur += prices[i] - prices[i-1]);
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
};
