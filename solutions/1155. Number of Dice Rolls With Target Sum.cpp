const int mod = 1e9+7;
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n+1,vector(target+1,-1));
        function<int(int,int)> dfs = [&](int count, int remain) {
            if(count==0 && remain==0)
                return 1;
            if(count ==0 || remain <=0)
                return 0;
            if(memo[count][remain]!=-1)
                return memo[count][remain];
            memo[count][remain]=0;
            for(int i=1;i<=k; ++i) {
                memo[count][remain] += dfs(count-1,remain-i);
                memo[count][remain] %= mod;
            }
            return memo[count][remain];
        };
        return dfs(n,target);
    }
};
