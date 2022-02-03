class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        for(int i=0;i<n;++i)
        {
            while(res.size() && res.back()> nums[i] && (n-1-i >= k- res.size()))
                  res.pop_back();
            if(res.size()<k)
                  res.push_back(nums[i]);
        }
        return res;
    }
};
