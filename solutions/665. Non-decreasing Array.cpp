class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int change=0;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]<nums[i-1]) {
                if(change==1)
                    return false;
                change++;
                if(i>1 && nums[i-2]<=nums[i] )
                    nums[i-1]= nums[i];
                else if(i>1 && nums[i-2]>nums[i])
                    nums[i]= nums[i-1];
            }
        }
        return change<2;
    }
};
