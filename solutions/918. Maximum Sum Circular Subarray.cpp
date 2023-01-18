class Solution {
public:
    int maxSubarraySum1Circular(vector<int>& nums) {
        const int n = nums.size();
        vector<int> right_max(n);
        right_max[n - 1] = nums[n - 1];
        for (int suffix_sum = nums[n - 1], i = n - 2; i >= 0; --i) {
            suffix_sum += nums[i];
            right_max[i] = max(right_max[i + 1], suffix_sum);
        }
        int max_sum = nums[0];
        int special_sum = nums[0];
        for (int i = 0, suffix_sum = 0, curMax = 0; i < n; ++i) {
            curMax = max(curMax, 0) + nums[i]; 
            max_sum = max(max_sum, curMax); // This is Kadane's algorithm.
            suffix_sum += nums[i];
            if (i + 1 < n) {
                special_sum = max(special_sum, suffix_sum + right_max[i + 1]);
            }
        }
        return max(max_sum, special_sum);
    }
    // https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = A[0], curMax = 0, minSum = A[0], curMin = 0;
        for (int& a : A) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
    int maxSubarraySumCircular2(vector<int>& nums) {
        int cur_max = 0, cur_min = 0, sum = 0, max_sum = nums[0], min_sum = nums[0];
        for (int num : nums) {
            cur_max = max(cur_max, 0) + num;
            max_sum = max(max_sum, cur_max);
            cur_min = min(cur_min, 0) + num;
            min_sum = min(min_sum, cur_min);
            sum += num;
        }
        return sum == min_sum ? max_sum : max(max_sum, sum - min_sum);
    }
};
