class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> seenIdx;
        int n = nums.size();
        for(int i=0;i<n;++i) {
            if(seenIdx.count(nums[i])) {
                if(i - seenIdx[nums[i]] <=k )
                    return true;
            }
            seenIdx[nums[i]]=i;
        }
        return false;
    }
};
