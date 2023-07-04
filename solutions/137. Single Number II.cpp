class Solution {
public:
    int singleNumber1(vector<int>& nums) {
        
        // Loner
        int loner = 0;
​
        // Iterate over all bits
        for (int shift = 0; shift < 32; shift++) {
            int bitSum = 0;
​
            // For this bit, iterate over all integers
            for (int num : nums) {
​
                // Compute the bit of num, and add it to bitSum
                bitSum += (num >> shift) & 1;
            }
​
            // Compute the bit of loner and place it
            int lonerBit = bitSum % 3;
            loner = loner | (lonerBit << shift);
        }
        return loner;
    }
    int singleNumber(vector<int>& nums) {
        
        // Initialize seenOnce and seenTwice to 0
        int seenOnce = 0, seenTwice = 0;
​
        // Iterate through nums
        for (int num : nums) {
            // Update using derived equations
            seenOnce = (seenOnce ^ num) & (~seenTwice);
            seenTwice = (seenTwice ^ num) & (~seenOnce);
        }
​
        // Return integer which appears exactly once
        return seenOnce;
    }
};
