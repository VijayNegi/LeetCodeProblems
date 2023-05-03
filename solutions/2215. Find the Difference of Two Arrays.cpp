class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1(begin(nums1),end(nums1)),n2(begin(nums2),end(nums2));
        vector<vector<int>> res(2);
        for(auto& n:n1)
            if(!n2.count(n)) res[0].push_back(n);
        
        for(auto& n:n2)
            if(!n1.count(n)) res[1].push_back(n);
        return res;
    }
};
