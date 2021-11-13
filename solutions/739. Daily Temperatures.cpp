class Solution {
public:
    // backward monotonic this is more efficient then forward monotonic - 144 ms
    vector<int> dailyTemperatures1(vector<int>& temps) {
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
    //forward monotonic - 231 ms
    vector<int> dailyTemperatures2(vector<int>& temps) {
        int n = temps.size();
        stack<int> stk;
        vector<int> res(n,0);
        for(int i= 0;i<n ;++i)
        {
            while(!stk.empty() && temps[stk.top()]< temps[i])
            {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
    // No stack ~ 151 ms
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        stack<int> stk;
        vector<int> res(n,0);
        int hottest = 0;
        for(int i= n-1;i>=0;--i)
        {
            if(temps[i]>= hottest)
            {
                hottest = temps[i];
                continue;
            }
            int days = 1;
            while( temps[i + days]<= temps[i])
            {
                days+= res[i+days];
            }
            res[i] = days;
        }
        return res;
    }
