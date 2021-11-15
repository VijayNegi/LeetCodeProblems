class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        
        int maxs = 1;
        int idx = 0;
        
        for(int i=1;i<n;++i)
        {
           for(int j=0;j<i;++j)
           {
               if(nums[i]%nums[j] ==0)
               {
                   dp[i] = max(dp[i], dp[j] +1);
               }
           }
            if(dp[i]>maxs)
            {
                maxs = dp[i];
                idx = i;
            }
        }
        
        vector<int> res;
        int prev=nums[idx];
        for(int k = idx; k>=0; --k)
        {
            if(dp[k]==maxs && prev%nums[k]==0)
            {
                res.push_back(nums[k]);
                --maxs;
                prev = nums[k];
            }
            
        }
        return res;
    }
};
