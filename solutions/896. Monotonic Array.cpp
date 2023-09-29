class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool inc = true;
        if(nums[0] > nums[n-1])
            inc = false;
        for(int i=1;i<n;++i){
            if(inc && (nums[i-1] >  nums[i]))
                return false;
            else if(!inc && (nums[i-1] < nums[i]))
                return false;
        }
        return true;
    }
};
