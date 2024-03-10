class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        int i,j;
        i=j=0;
        unordered_set<int> inter;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j])
                ++i;
            else if(nums1[i]>nums2[j])
                ++j;
            else {
                inter.insert(nums1[i]);
                ++i,++j;
            }
        }
        vector<int> result(inter.begin(),inter.end());
        return result;
    }
};
