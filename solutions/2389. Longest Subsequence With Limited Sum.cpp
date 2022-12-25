class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=1;i<n;++i)
            nums[i] += nums[i-1];
        vector<int> result;
        for(auto q:queries){
            auto pos = upper_bound(nums.begin(),nums.end(),q);
            result.push_back(distance(nums.begin(),pos));
        }
        return result;
    }
};
