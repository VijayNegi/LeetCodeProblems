class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort (nums.begin(), nums.end());
        int mid = nums[n/2], i = 0, count = 0;
        for(auto& c:nums) {
            count += abs(c-mid);
        }
        return count;
    }
};
