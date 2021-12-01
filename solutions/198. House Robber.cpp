class Solution {
public:
    int rob1(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        else if(n==2)
            return max(nums[0],nums[1]);
        
        vector<int> dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<n;++i)
        {
            dp[i] = max(nums[i]+ dp[i-2], dp[i-1]);
        }
        
        return dp[n-1];
    }
    //with O(1) space
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        else if(n==2)
            return max(nums[0],nums[1]);
        
        int dp[2],curr;
        
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        
        for(int i=2;i<n;++i)
        {
            curr = max(nums[i]+ dp[0], dp[1]);
            dp[0] = dp[1];
            dp[1] = curr;
        }
        
        return dp[1];
    }
};
