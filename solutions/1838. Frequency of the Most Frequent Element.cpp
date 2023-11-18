class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int l=0;
        int n = nums.size();
        int result=1;
        long sum = nums[0];
        for(int i=1;i<n;++i){
            sum += nums[i];
            while((long)nums[i]*(i-l+1) - sum > k)
                sum -=nums[l++];
    
            result = max(result,i-l+1);
        }
        return result;
    }
};
