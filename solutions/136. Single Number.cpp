class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int unique=0;
        for(auto a:nums)
            unique ^=a; 
        return unique;
    }
};
