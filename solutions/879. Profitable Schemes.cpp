const int mod = 1e9+7;
class Solution {
    int memo[101][101][101];
public:
    // official solution
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit)    {
        int k = group.size();
        memset(memo, -1,sizeof(memo));
        function<int(int,int,int)> dfs = [&](int pos,int count,int pro)-> int{
            if(pos == k)
                return pro >= minProfit;
            if(memo[pos][count][pro] != -1) return memo[pos][count][pro];
            int ways = dfs(pos+1,count,pro);
            if(count + group[pos]<=n)
                ways += dfs(pos+1,count+group[pos],min(minProfit, pro + profit[pos])); 
            return memo[pos][count][pro] = ways%mod;
        };
        return dfs(0,0,0);
    }
};
