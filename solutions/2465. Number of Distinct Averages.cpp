class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<int> distinct;
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while(l<r){
            distinct.insert(nums[l++]+nums[r--]);
        }
        return distinct.size();
    }
};
