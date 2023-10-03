class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> freq;
        int result=0;
        for(auto& n: nums){
            result += freq[n];
            freq[n]++;
        }
        return result;
    }
};
