class Solution {
public:
    
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int min_idx=0,start=INT_MAX;
        int max_idx=n-1,end=-1;
        vector<int> sorted = nums;
        sort(sorted.begin(),sorted.end());
        
        while(n--)
        {
            if(nums[min_idx] == sorted[min_idx])
                min_idx++;
            if(nums[max_idx] == sorted[max_idx])
                max_idx--;
        }
        
        if(max_idx>min_idx)
            return max_idx - min_idx + 1;
        return 0;
        
    }
    //wrongans
    int findUnsortedSubarray2(vector<int>& nums) {
        int n = nums.size();
        int min_idx=0,start=INT_MAX;
        int max_idx=0,end=-1;
        
        for(int i=1;i<n;++i)
        {
            if(nums[i]<nums[min_idx])
            {
                if(start>min_idx)
                    start = min_idx;
                if(end<i)
                    end = i;
                
                min_idx = i;
            }
            if(nums[i]<nums[max_idx])
            {
                if(start>max_idx)
                    start = max_idx;
                if(end<i)
                    end = i;
            }
            if(nums[i]>nums[max_idx])
            {
                max_idx = i;
            }
        }
        if(end!=-1)
            return end - start + 1;
        return 0;
        
    }
    //wrongans
    int findUnsortedSubarray1(vector<int>& nums) {
        int n = nums.size();
        int start=INT_MAX;
        int end = -1;
        for(int i=0;i<n-1;++i)
        {
            if(nums[i]>nums[i+1])
            {
                if(start>i)
                    start = i;
                if(end<i+1)
                    end = i+1;
            }
        }
        
        if(end!=-1)
            return end - start + 1;
        return 0;
    }
};
