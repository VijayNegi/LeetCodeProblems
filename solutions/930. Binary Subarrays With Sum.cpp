class Solution {
public:
    // prefix sum
    int numSubarraysWithSum1(vector<int>& nums, int goal) {
        int totalCount = 0;
        int currentSum = 0;
        // {prefix: number of occurrence}
        unordered_map<int, int> freq; // To store the frequency of prefix sums
​
        for (int num : nums) {
            currentSum += num;
            if (currentSum == goal){
                totalCount++;
            }
​
            // Check if there is any prefix sum that can be subtracted from the current sum to get the desired goal
            if (freq.find(currentSum - goal) != freq.end()){
                totalCount += freq[currentSum - goal];
            }
​
            freq[currentSum]++;
        }
​
        return totalCount;
    }
    // Sliding window
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int start = 0;
        int prefixZeros = 0;
        int currentSum = 0;
        int totalCount = 0;
        
        // Loop through the array using end pointer
        for (int end = 0; end < nums.size(); ++end) {
            // Add current element to the sum
            currentSum += nums[end];
            
            // Slide the window while condition is met
            while (start < end && (nums[start] == 0 || currentSum > goal)) {
                if (nums[start] == 1) {
                    prefixZeros = 0;
                } else {
                    prefixZeros += 1;
                }
                
                currentSum -= nums[start];
                start += 1;
            }
            
            // Count subarrays when window sum matches the goal
            if (currentSum == goal) {
                totalCount += 1 + prefixZeros;
            }
        }
        
        return totalCount;
    }
};
