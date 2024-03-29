class Solution {
public:
    int maxProductDifference1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - 1] * nums[nums.size() - 2] - nums[0] * nums[1];
    }
    int maxProductDifference(vector<int>& nums) {
        int biggest = 0;
        int secondBiggest = 0;
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;
        
        for (int num : nums) {
            if (num > biggest) {
                secondBiggest = biggest;
                biggest = num;
            } else {
                secondBiggest = max(secondBiggest, num);
            }
            
            if (num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else {
                secondSmallest = min(secondSmallest, num);
            }
        }
        
        return biggest * secondBiggest - smallest * secondSmallest;
    }
};
