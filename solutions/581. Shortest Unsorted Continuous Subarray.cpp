class Solution {
public:
    int findUnsortedSubarray1(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
         int l=n-1,r=0;
        int low = nums[n-1];
        int high = nums[0];
        
        for(int i=1;i<n;++i)
        {
            if(nums[i]>=high)
                high = nums[i];
            else
                r=i;
        }
        
        for(int i=n-2;i>=0;--i)
        {
            if(nums[i]<=low)
                low = nums[i];
            else
                l=i;
        }
        if(l<r)
            return r-l+1;
        return 0;
    }
    // Think of problem as - In ideal sorted array. 
    // Every element from right to left will be smaller.
    // Every element from left to right will be larger.
    // finding atual position of Min by going right to left you will get start.
    // finding atual position of max by going left to right you will get end.
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minV = nums[n-1];
        int maxV = nums[0];
        int start= -1;
        int end = -2;
        
        for(int i=0;i<n;++i)
        {
            minV = min(nums[n-1-i],minV);
            maxV = max(nums[i],maxV);
            if(nums[i] < maxV) end = i;
            if(nums[n-1-i]>minV) start = n-1-i;
        }
        
        return end - start +1;
    }
};
