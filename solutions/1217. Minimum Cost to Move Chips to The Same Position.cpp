class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int dp[2]={0};
        for(auto& p:position)
        {
            ++dp[p%2];
        }
        return min(dp[0],dp[1]);
    }
};
