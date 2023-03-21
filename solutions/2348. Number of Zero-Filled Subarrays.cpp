class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result=0;
        int k=0;
        for(auto n:nums){
            if(n==0){
                ++k;
                result+=k;
            }
            else k=0;
        }
        return result;
    }
};
