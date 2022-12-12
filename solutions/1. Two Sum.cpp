class Solution {
public:
    vector<int> twoSum1(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        for(int i=0;i<nums.size();++i){
            if(seen[target - nums[i]])
                return {seen[target - nums[i]]-1,i};
            seen[nums[i]] = i+1;
        }
        return {0,0};
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        for(int i=0;i<nums.size();++i)
        {
            auto it = hashmap.find(target - nums[i]);
            if(it!=hashmap.end())
                return {it->second,i};
            hashmap[nums[i]] = i;
        }
        return {};
    }
};
