class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sumseen;
        sumseen[0]++;
        
       int count=0;
        int  n = nums.size();
        int sum=0;
        for(auto a:nums)
        {
            sum+=a;
           count += sumseen[sum-k];
           ++sumseen[sum];
        }
        
        return count;
    }
};
