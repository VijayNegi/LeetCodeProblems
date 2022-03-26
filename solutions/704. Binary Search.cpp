class Solution {
public:
    // using stl
    int search1(vector<int>& nums, int target) {
        auto it = lower_bound(begin(nums),end(nums),target);
        if(it != nums.end())
        {
            if(*it==target)
                return distance(nums.begin(),it);
        }
         return -1;   
    }
    // binary search
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
        while(l<=r)
        {
            mid = l + (r-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                r = mid-1;
            else
                l = mid+1;
        }
        return -1;
    }
};
