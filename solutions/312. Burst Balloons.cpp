class Solution {
public:
    int pop(vector<int>& nums, int l,int r)
    {
        //cout<<"l="<<l<<" r="<<r<<endl;
        if(r<=l || r-l == 1) // no balloon to pop
            return 0;
        if(r-l == 2) // one balloon to pop
        {
            return nums[l]*nums[l+1]*nums[r];
        }
        
        // otherwise find biggest ballon in this range and burst it last,
        int mIdx = l+1;
        for(int i = l+2;i<r;++i)
        {
            if(nums[i]>nums[mIdx])
                mIdx = i;
        }
        //cout<<"max="<<nums[mIdx]<<endl;
        
        int res = pop(nums,l,mIdx);
        res += pop(nums,mIdx,r);
        
        res += nums[l]*nums[mIdx]*nums[r];
        return res;
        
    }
    // this will give WA , as removing largest element last might not result in max coins
    int maxCoins1(vector<int>& nums) {
        int n = nums.size();
        int res=0;
        if(n==1)
        {
            return nums[0];
        }
        else if(n==2)
        {
            res = nums[0]*nums[1];
            res += (nums[0]>nums[1])? nums[0]: nums[1];
            return res;
        }
        else if(n==3)
        {
            res = nums[0]*nums[1]*nums[2];
            res += nums[0]*nums[2];
            res += (nums[0]>nums[2])? nums[0]: nums[2];
            return res;
        }
        
         res = pop(nums,0,n-1);
         res += nums[0]*nums[n-1];
         res += (nums[0]>nums[n-1])? nums[0]: nums[n-1];
        return res;

    }
    // dp with same subproblem as above but not poping largest element
    int maxCoins(vector<int> &iNums) {
        int nums[iNums.size() + 2];
        int n = 1;
        for (int x : iNums) if (x > 0) nums[n++] = x;
        nums[0] = nums[n++] = 1;

        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        
        for (int k = 2; k < n; ++k) {
            for (int left = 0; left < n - k; ++left)
            {
                int right = left + k;
                for (int i = (left + 1); i < right; ++i)
                    dp[left][right] = max(dp[left][right],
                         nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
            }
        }

        return dp[0][n - 1];
    }
};
