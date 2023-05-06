const int mod = 1e9+7;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        long ans=0;
        int n = nums.size();
        vector<long> power(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }
​
        int left = 0, right = n - 1;
​
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans += power[right - left];
                ans %= mod;
                left++;
            } else {
                right--;
            }
        }
        
        return ans;
    }
};
