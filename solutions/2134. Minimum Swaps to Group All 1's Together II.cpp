class Solution {
public:
    //contest 120 ms
    int minSwaps1(vector<int>& nums) {
        int n = nums.size();
        int totalOne = 0;
        for(auto k:nums)
            if(k==1)
                ++totalOne;
        
        if(totalOne>=n-1)
            return 0;
        
        int tempone = 0;
        
        int i=0;
        while(i<totalOne)
            if(nums[i++]) ++tempone;
        
        int maxones=tempone;
        for(;i<(totalOne+n);++i)
        {
            int end = i%n;
            int st = (i-totalOne)%n;
            
            if(nums[end]==1)
                ++tempone;
            if(nums[st]==1)
                --tempone;
            maxones = max(maxones,tempone);
    
        }
        
        return totalOne - maxones;
    }
    //cleaner : 80 ms
    int minSwaps(vector<int>& nums) {
        int n = size(nums);
        int ones = count(begin(nums), end(nums), 1);
        int cnt = count(begin(nums), begin(nums) + ones, 1);
        int ans = ones - cnt;
        for(int i = 1; i < n; i++)
        {
            cnt += nums[(i + ones - 1) % n] - nums[i - 1];
            ans = min(ans, ones - cnt);
        }
            
        return ans;
    }
};
