class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long result=nums[0],n=nums.size();
        long sum=nums[0];
        for(int i=1;i<n;++i){
            sum+=nums[i];
            result = max(result,(sum+i)/(i+1L));
        }
        return result;
    }
};
