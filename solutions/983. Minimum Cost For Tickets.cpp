class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
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
};
