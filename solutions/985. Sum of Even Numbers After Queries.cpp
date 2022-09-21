class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sum=0;
        for(auto& n:nums)
            if(!(n & 1))  sum += n;
        vector<int> result;
        for(auto& q:queries){
            int idx = q[1];
            int val = q[0];
            if(!(nums[idx] & 1))  sum -= nums[idx];
            nums[idx]+= val;
            if(!(nums[idx] & 1))  sum += nums[idx];
            result.push_back(sum);
        }
        return result;
    }
};
