class Solution {
public:
    // using property xor: n ^ n is null, so we xor all numbers and array, missing n will be left. 39ms
    int missingNumber1(vector<int>& nums) {
        int res = 0;
        int i=0;
        for(auto n:nums)
        {
            res = (res^n)^i++;
        }
        
        res = res^i;
        
        return res;
    }
    // using property sum of n nums: n(n+1)/2 , 33 ms
    int missingNumber(vector<int>& nums) {
        int sum = accumulate(begin(nums),end(nums),0);
        int n = nums.size();
        int sum_natural = n*(n+1)/2;
        
        return sum_natural - sum;
    }
    
};
