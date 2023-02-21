class Solution {
public:
    //self
    int singleNonDuplicate2(vector<int>& nums) {
        int l,r,n;
        n = nums.size();
        l=0,r=n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mid%2){
                if(mid>0 && nums[mid]==nums[mid-1]){
                    l=mid+1;
                }
                else if(mid<n-1 && nums[mid]==nums[mid+1])
                    r = mid-1;
                else return nums[mid];
            }
            else {
                if(mid<n-1 && nums[mid]==nums[mid+1]){
                    l=mid+1;
                }
                else if(mid>0 && nums[mid]==nums[mid-1])
                    r = mid-1;
                else return nums[mid];
            }
        }
        return -1;
    }
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
