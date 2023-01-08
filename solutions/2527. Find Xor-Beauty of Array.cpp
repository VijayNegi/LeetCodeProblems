class Solution {
public:
    int xorBeauty1(vector<int>& nums) {
        int result = nums[0];
        for(int i=1;i<nums.size();++i)
            result = result ^ nums[i];
        return result;
    }
    int xorBeauty(const vector<int>& nums) {
        return accumulate(begin(nums), end(nums), 0, bit_xor{});
    }
};
