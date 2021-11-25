class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxsum = INT_MIN;
        for(auto& n:nums)
        {
            sum = max(sum + n,n);
            maxsum = max(maxsum,sum);
        }
        return maxsum;
    }
};
