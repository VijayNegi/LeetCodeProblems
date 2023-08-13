class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1,false);
        function<bool(int)> dfs = [&](int idx){
            if(idx == n)
                return true;
            if(idx == n-1)
                return false;
            if(dp[idx]) return false;
            if(nums[idx] == nums[idx+1])
                if(dfs(idx+2))
                    return true;
            if(idx<=n-3){
                bool valid =false;
                if(nums[idx] == nums[idx+1] && (nums[idx+1]==nums[idx+2]))
                    valid = true;
                if(!valid && (nums[idx] +1 == nums[idx+1]) && (nums[idx+1] +1 ==nums[idx+2]))
                    valid =  true;
                if(valid && dfs(idx+3))
                        return true;
            }
            dp[idx] = true;
            return false;
        };
        return dfs(0);
    }
};
