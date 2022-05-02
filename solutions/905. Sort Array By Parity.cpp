class Solution {
public:
    // stl : 3 ms
    vector<int> sortArrayByParity1(vector<int>& nums) {
        auto cmp = [](int l,int r){return ((l & 1) < (r&1));};
        sort(begin(nums),end(nums),cmp);
        return nums;
    }
    //two-pointers: 8 ms
    vector<int> sortArrayByParity2(vector<int>& nums) {
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
    //two-pointers(unessesory swaps): 7 ms
     vector<int> sortArrayByParity(vector<int> &A) {
        for (int i = 0, j = 0; j < A.size(); j++)
            if (A[j] % 2 == 0) swap(A[i++], A[j]);
        return A;
    }
};
