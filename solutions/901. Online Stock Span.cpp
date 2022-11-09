class StockSpanner {
    int day{0};
    vector<vector<int>> mstk;
    stack<pair<int,int>> stack;
public:
    StockSpanner() {
    }
    //self
    // 604ms
    int next1(int price) {
        ++day;
        while(mstk.size() && mstk.back()[1]<=price)
            mstk.pop_back();
        int result = mstk.size()? day - mstk.back()[0]: day;
        mstk.push_back({day,price});
        return result;
    }
    // other answers
    // 227 ms, might be because of pairs
    int next(int price) {
        int ans = 1;
        while (!stack.empty() && stack.top().first <= price) {
            ans += stack.top().second;
            stack.pop();
        }
        stack.push({price, ans});
        return ans;
    }
};
​
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
