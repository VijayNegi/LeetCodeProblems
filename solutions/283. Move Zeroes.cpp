class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int d,n;
        d=0;
        n = nums.size();
        for(int i=0;i<n;++i)
        {
            if(nums[i]!=0)
                nums[d++] = nums[i];
        }
        for(int i=d;i<n;++i)
            nums[i] = 0;
    }
};
