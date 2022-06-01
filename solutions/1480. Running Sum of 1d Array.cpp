class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result = nums;
        for(int i=1;i<result.size();++i) {
            result[i] +=result[i-1];
        }
        return result;
    }
};
