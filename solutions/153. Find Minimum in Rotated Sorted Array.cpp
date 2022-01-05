class Solution {
public:
    int findMin1(vector<int>& nums) {
        int n = nums.size();
        int l,h;
        l=0,h=n-1;
        while(l<h)
        {
            int mid = (l + h)/2;
            if(nums[h]< nums[l])
            {
                if(nums[mid]> nums[h])
                    l = mid +1;         // +1 because this definately cannot be smallest
                else
                    h = mid;
            }
            else
                break;//h = mid-1;  // -1 because this definately cannot be smallest
        }
        return nums[l];
    }
    // other ways
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l,h;
        l=0,h=n-1;
        while(l<h)
        {
            int mid = (l + h)/2;
            if(nums[mid] > nums[h])
                l = mid + 1;
            else
               h = mid;
        }
        return nums[l];
    }
};
