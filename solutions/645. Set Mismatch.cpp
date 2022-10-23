        for(int i = 0; i<nums.size() ; i++){
            if(nums[i] != i + 1)return {nums[i], i + 1};
        }
        return {0,1}; // dummy
    }
    // const space 
    vector<int> findErrorNums3(vector<int>& nums) {
        int dup = -1, missing = 1;
        for (int n: nums) {
            if (nums[abs(n) - 1] < 0)
                dup = abs(n);
            else
                nums[abs(n) - 1] *= -1;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0)
                missing = i + 1;
        }
        return {dup, missing};
    }
    // xor
    // https://leetcode.com/problems/set-mismatch/discuss/1089568/C%2B%2B-Simple-Bit-Manipulation-Solution
    vector<int> findErrorNums(vector<int>& nums) {
        // Create distinct vector
        set<int> distinct1{nums.begin(), nums.end()};
        vector<int> distinct{distinct1.begin(), distinct1.end()};
        
        int missing = distinct.size(), duplicate = 0, n = nums.size();
        
        // Find missing number
        for (int i = 0; i < n-1; i++)
            missing ^= i ^ distinct[i];
        missing ^= n;
        
        // Find duplicate number
        for (int i = 0; i < n-1; i++) {
            duplicate ^= nums[i] ^ distinct[i];
        }
        duplicate ^= nums[n-1];
        
        return {duplicate, missing};
    }
};
