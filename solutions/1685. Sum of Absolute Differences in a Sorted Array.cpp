class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        long sum =  accumulate(begin(nums),end(nums),0);
        vector<int> result;
        int n = nums.size();
        int pre = 0;
        int count= 0 ;
        for(int i=0;i<n;++i){
            result.push_back(abs(nums[i]*(n-i) - sum + pre) + abs(nums[i]*i-pre));
            pre += nums[i];
        }
        return result;
    }
};
