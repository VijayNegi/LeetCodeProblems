class Solution {
public:
    // stl : 13 ms
    vector<int> sortArrayByParity1(vector<int>& nums) {
        auto cmp = [](int l,int r){if ((l & 1) < (r&1))
                                   return true;
                                   return false;};
        sort(begin(nums),end(nums),cmp);
        return nums;
    }
    //two-pointers: 8 ms
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size()-1;
        int l=0,r=n;
        while(l<r)
        {
            while(l<r && (nums[l] &1) ==0)
                ++l;
            while(l<r && (nums[r] &1) ==1)
                --r;
            swap(nums[l],nums[r]);
            ++l,--r;
        }
        return nums;
    }
};
