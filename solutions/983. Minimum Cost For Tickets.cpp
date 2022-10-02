class Solution {
public:
    // self
    int mincostTickets1(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> mincost(n+1,-1);
        function<int(int)> dfs = [&](int day) {
            if(day>=n)
                return 0;
            if(mincost[day]!= -1)
                return mincost[day];
            int cost = INT_MAX;
            cost = min(cost,dfs(day+1) + costs[0]);
            int k=day;
            while(k<n && ((days[k] - days[day])<7))  k++;
            cost = min(cost,dfs(k) + costs[1]);
            while(k<n && ((days[k] - days[day])<30))  k++;
            cost = min(cost,dfs(k) + costs[2]);
            mincost[day] = cost;
            return cost;
        };
        return dfs(0);
    }
    // bottom up 
    int mincostTickets(vector<int>& DAYS, vector<int>& cost) {
        
        unordered_set<int> days(DAYS.begin(),DAYS.end());
        vector<int> dp(367);
        
        for(int i=1 ; i<366 ; i++)
        {
            dp[i] = dp[i-1];
            if(days.find(i) != days.end())
            {
            // cost of ith day , decision of ith day will be
                dp[i] = min({ dp[i - 1] + cost[0],   // 1st case
                             dp[max(0, i - 7)] + cost[1],  // 2nd case
                             dp[max(0, i - 30)] + cost[2]});  // 3rd case
            }
        }
        return dp[365];
    }
};
