class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
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
};
