class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minV = nums[n-1];
        int maxV = nums[0];
        int start= -1;
        int end = -2;
        
        for(int i=0;i<n;++i)
        {
            minV = min(nums[n-1-i],minV);
            maxV = max(nums[i],maxV);
            if(nums[i] < maxV) end = i;
            if(nums[n-1-i]>minV) start = n-1-i;
        }
        
        return end - start +1;
    }
};
