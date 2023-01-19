class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> seen;
        int sum=0;
        seen[0]=1;
        int result=0;
        for(auto& n:nums){
            sum = (sum +(n%k+k)%k)%k;
            result += seen[sum];
            seen[sum]++;
        }
        return result;
    }
};
