            int j = i;
            while (--j >= 0) 
                if (sidesLength[i] == sidesLength[j]) 
                    break;
            if (j != -1) continue;
            sidesLength[i] += matches[index];
            if (dfs(sidesLength, matches, index + 1, target))
                return true;
            sidesLength[i] -= matches[index];
        }
        return false;
    }
    //https://leetcode.com/problems/matchsticks-to-square/discuss/95744/cpp-6ms-solution-with-DFS
    bool makesquare3(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = accumulate(begin(nums),end(nums),0);
        if (sum % 4 != 0) return false;
        sort(begin(nums),end(nums),greater<>()); 
        if(nums[0] > sum/4)
            return false;
        vector<int> sidesLength(4, 0);
        return dfs(sidesLength, nums, 0, sum / 4);
    }
    // another neat solution
    //https://leetcode.com/problems/partition-to-k-equal-sum-subsets/discuss/480707/C%2B%2B-DP-bit-manipulation-in-20-lines
     bool makesquare(vector<int>& nums) {
        int k=4;
        int n = nums.size(), sum = 0;
        vector<int> dp((1<<16)+2,-1);
        //fill(dp, dp+(1<<16)+2, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % k) return false;
        int tar = sum/k;
        
        for (int mask = 0; mask < (1<<n); mask++) {
            if (dp[mask] == -1) continue;  // if current state is illegal, simply ignore it
            for (int i = 0; i < n; i++) {
                if (!(mask&(1<<i)) && dp[mask]+nums[i] <= tar) {  // if nums[i] is unchosen && choose nums[i] would not cross the target
                    dp[mask|(1<<i)] = (dp[mask]+nums[i]) % tar;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
    }
    
};
