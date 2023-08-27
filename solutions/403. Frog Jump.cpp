class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> pos;
        int n = stones.size();
        for(int i=0;i<n;++i){
            pos[stones[i]] = i;
        }
        vector<map<int,bool>> dp(n);
        function<bool(int,int)> dfs = [&](int j, int p){
            if(p==n-1)
                return true;
            if(dp[p].count(j))
                return dp[p][j];
            int jump = j-1;
            dp[p][j] = false;
            for(int k=j-1;k<=j+1;++k){
                int next = stones[p]+k;
                if(next>stones[p] && pos.count(next)){
                    dp[p][j] = dp[p][j] || dfs(k,pos[next]);
                }
            }
            return dp[p][j];
        };
        return dfs(0,0);
    }
};
