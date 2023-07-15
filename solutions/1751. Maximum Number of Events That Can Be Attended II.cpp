class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n = events.size();
        vector<vector<int>> dp(n,vector(k+1,-1));
        function<int(int,int,int)> dfs = [&](int idx, int count,int start){
            if(idx>=n || count==0) return 0;
            if(start > events[idx][0]) return dfs(idx+1,count,start);
            if(dp[idx][count]!= -1) return dp[idx][count];
            dp[idx][count] = dfs(idx+1,count,start);
            //for(int i = idx; i<n ; ++i){
                int temp = dfs(idx+1,count-1,events[idx][1]+1);
                dp[idx][count] = max(dp[idx][count], temp + events[idx][2]);
            //}
            return dp[idx][count];
        };
        return dfs(0,k,0);
    }
};
