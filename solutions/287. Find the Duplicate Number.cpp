class Solution {
public:
    // property of n natual numbers
    int findDuplicate1(vector<int>& nums) {
        int ans = -1;
        
        for(auto& a:nums)
        {
            if(nums[abs(a)]<0)
            {
                ans = abs(a);
                break;
            }
            else
                nums[abs(a)] = -1* nums[abs(a)];
        }
        for(auto& a:nums)
            if(a<0)
                a = -1*a;
        
        return ans;
    }
    int findDuplicate(vector<int>& nums) {
        int slow(0),fast(0);
        
        while(true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow==fast)
                break;
        }
        
        slow = 0;
        while(true)
        {
            slow = nums[slow];
            fast = nums[fast];
            if(slow==fast)
                break;
        }
        return slow;
    }
};
