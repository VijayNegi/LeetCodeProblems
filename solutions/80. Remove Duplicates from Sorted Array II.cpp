class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int s=1,d=0;
        bool twice=false;
        for(int d=1;d<n;++d)
        {
            if(nums[d]==nums[d-1] && twice)
                continue;
            else if(nums[d]==nums[d-1] )
            {
                twice = true;
                nums[s++] = nums[d];
            }
            else
            {
                twice =false;
                nums[s++] = nums[d];
            }
        }
        return s;
    }
};
