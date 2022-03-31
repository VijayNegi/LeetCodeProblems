                    continue;
                }
​
                // Otherwise, use the recurrence relation to determine the minimum largest subarray
                // sum between currIndex and the end of the array with subarrayCount subarray remaining.
                int minimumLargestSplitSum = INT_MAX;
                for (int i = currIndex; i <= n - subarrayCount; i++) {
                    // Store the sum of the first subarray.
                    int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];
​
                    // Find the maximum subarray sum for the current first split.
                    int largestSplitSum = max(firstSplitSum, memo[i + 1][subarrayCount - 1]);
​
                    // Find the minimum among all possible combinations.
                    minimumLargestSplitSum = min(minimumLargestSplitSum, largestSplitSum);
​
                    if (firstSplitSum >= minimumLargestSplitSum) {
                        break;
                    }
                }
​
                memo[currIndex][subarrayCount] = minimumLargestSplitSum;
            }
        }
        
        return memo[0][m];
    }
    
    // ***** binary search 0 ms
    int minimumSubarraysRequired(vector<int>& nums, int maxSumAllowed) {
        int currentSum = 0;
        int splitsRequired = 0;
        
        for (int element : nums) {
            // Add element only if the sum doesn't exceed maxSumAllowed
            if (currentSum + element <= maxSumAllowed) {
                currentSum += element;
            } else {
                // If the element addition makes sum more than maxSumAllowed
                // Increment the splits required and reset sum
                currentSum = element;
                splitsRequired++;
            }
        }
        
        // Return the number of subarrays, which is the number of splits + 1
        return splitsRequired + 1;
    }
    
    int splitArray(vector<int>& nums, int m) {
        // Find the sum of all elements and the maximum element
        int sum = 0;
        int maxElement = INT_MIN;
        for (int element : nums) {
            sum += element;
            maxElement = max(maxElement, element);
        }
        
        // Define the left and right boundary of binary search
        int left = maxElement;
        int right = sum;
        int minimumLargestSplitSum = 0;
        while (left <= right) {
            // Find the mid value
            int maxSumAllowed = left + (right - left) / 2;
            
            // Find the minimum splits. If splitsRequired is less than
            // or equal to m move towards left i.e., smaller values
            if (minimumSubarraysRequired(nums, maxSumAllowed) <= m) {
                right = maxSumAllowed - 1;
                minimumLargestSplitSum = maxSumAllowed;
