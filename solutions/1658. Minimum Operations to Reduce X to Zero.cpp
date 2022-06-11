class Solution {
public:
    // hashmap 706 ms
    int minOperations1(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int,int> pre;
        int sum = nums[0];
        pre[sum] = 1;
        for(int i=1;i<n;++i) {
            sum += nums[i];
            pre[sum] = i+1;
        }
        sum = 0;
        int result = n+1;
        if(pre[x])
            result = pre[x];
        for(int i=n-1;i>=0;--i) {
            sum += nums[i];
            if(sum==x)
                result = min(result, n-i);
            if(pre[x-sum])
                result = min(result,pre[x-sum] + n-i);
        }
        if(result == n+1)
            return -1;
        return result;
        
    }
    // sliding window 272 ms
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (int num: nums) sum += num;
​
        int maxLength = -1, currSum = 0;
        for (int l=0, r=0; r<nums.size(); r++) {
            currSum += nums[r];
            while (l <= r && currSum > sum - x) currSum -= nums[l++];
            if (currSum == sum - x) maxLength = max(maxLength, r-l+1);
        }
​
        return maxLength == -1 ? -1 : nums.size() - maxLength;
    }
};
