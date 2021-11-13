class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        stack<int> stk;
        vector<int> res(n,0);
        for(int i= n-1;i>=0;--i)
        {
            while(!stk.empty() && temps[stk.top()]<= temps[i])
                stk.pop();
            if(!stk.empty())
                res[i] = stk.top() - i;
            
            stk.push(i);
        }
        return res;
    }
};
