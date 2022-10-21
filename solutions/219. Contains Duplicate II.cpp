class Solution {
public:
    // map solution
    bool containsNearbyDuplicate1(vector<int>& nums, int k) {
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
    // set solution
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                st.erase(nums[i - k - 1]);
            }
            if (!st.insert(nums[i]).second) {
                return true;
            }
        }
        return false;
    }
};
