class Solution {
public:
    // nlogn 143 ms
    bool containsDuplicate1(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size()-1;++i)
            if(nums[i]==nums[i+1])
                return true;
        return false;
    }
    // O(n) 89 ms
    bool containsDuplicate2(vector<int>& nums) {
        unordered_set<int> seen;
        
        for(auto&  n:nums)
        {
            if(seen.count(n))
                return true;
            seen.insert(n);
        }   
        return false;
    }
    // one liner 109 ms
    bool containsDuplicate(vector<int>& nums) {
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
};
