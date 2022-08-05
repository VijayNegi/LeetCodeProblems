class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<uint32_t> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;++i)
            for(auto& k:nums) {
                if(k<=i)
                    dp[i] += dp[i-k];
            }
        return dp[target];
    }
};
