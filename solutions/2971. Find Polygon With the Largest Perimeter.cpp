class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums),end(nums));
        long sum = accumulate(begin(nums),end(nums),(long)0);
        int n = nums.size();
        for(int i=n-1;i>1;--i){
            if(sum - nums[i]>nums[i])
                return sum;
            sum -=nums[i];
        }
        return -1;
    }
};
