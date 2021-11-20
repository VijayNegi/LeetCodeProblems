class Solution {
public:
    //xor
    int singleNonDuplicate1(vector<int>& nums) {
        int ans(0);
        
        for(const auto& n:nums)
        {
            ans ^=n;
        }
        return ans;
    }
    // O(log n)
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        
        while(l<r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == nums[mid ^ 1])
                l = mid +1;
            else
                r = mid;
        }
        return nums[l];
    }
};
