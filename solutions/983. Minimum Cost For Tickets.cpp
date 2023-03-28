class Solution {
public:
    int mincostTickets1(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> memo(n,-1);
        function<int(int)> dfs = [&](int id){
            if(id>=n) return 0;
            if(memo[id]!=-1) return memo[id];
            int cost = 0;
            // one day pass
            cost = dfs(id+1)+costs[0];
            // one week pass
            int w =id+1;
            while(w<n && days[w] < (days[id]+7)) w++;
            cost  = min(cost, dfs(w)+costs[1]);
            // one month pass
            w =id+1;
            while(w<n && days[w] < (days[id]+30)) w++;
            cost  = min(cost, dfs(w)+costs[2]);
            return memo[id]=cost;
        };
        return dfs(0);
    }
    / bottom up 
    int mincostTickets(vector<int>& DAYS, vector<int>& cost) {
        
        unordered_set<int> days(DAYS.begin(),DAYS.end());
        vector<int> dp(367);
        
        for(int i=1 ; i<366 ; i++)
        {
            dp[i] = dp[i-1];
            if(days.find(i) != days.end())
            {
			// cost of ith day , decision of ith day will be
                dp[i] = min({ dp[i - 1] + cost[0],   // 1st case
                             dp[max(0, i - 7)] + cost[1],  // 2nd case
                             dp[max(0, i - 30)] + cost[2]});  // 3rd case
            }
        }
        return dp[365];
    }
};
