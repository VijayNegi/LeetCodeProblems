class Solution {
public:
    //dp - 2D
    int findLength2(vector<int>& nums1, vector<int>& nums2) {
        
        int result=0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        
        for(int i=0;i<len1;++i)
        {
            for(int j=0;j<len2;++j)
            {
                if(nums1[i]==nums2[j])
                {
                    dp[i+1][j+1] = dp[i][j] + 1;
                    result = max(result, dp[i+1][j+1]);
                }
            }
        }
        
        return result;
    }
    // dp - space optimized
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()< nums2.size())
            return findLength(nums2,nums1);
        int result=0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> pre(len2+1,0);
        vector<int> curr(len2+1,0);
        
        for(int i=0;i<len1;++i)
        {
            for(int j=0;j<len2;++j)
            {
                if(nums1[i]==nums2[j])
                {
                    curr[j+1] = pre[j] + 1;
                    result = max(result, curr[j+1]);
                }
            }
            fill(pre.begin(), pre.end(), 0);
            swap(curr,pre);
        }
        
        return result;
    }
​
};
​
​
​
