class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0,r = nums.size()-1;
        while(l<=r)
        {
            int mid = l+ (r-l)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[l] == nums[r])
                ++l;
            else if(nums[l]<=nums[mid]) // decide on which part you are i.e. first sorted array or second.
            {
                if(target>=nums[l] && target<nums[mid])
                    r = mid -1;
                else
                    l = mid +1;
            }
            else
            {
                if(target>nums[mid] && target<=nums[r])
                    l = mid +1;
                else
                    r = mid -1;
            }
        }
        return false;
    }
};
