class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        //vector<unordered_map<int,int>> dp(n);   // TLE
         vector<vector<int>> dp(n, vector<int>(2000, 0));
        int result=0;
        for(int i=1;i<n;++i){
            for(int j=i-1;j>=0;--j){
                int diff = nums[i]-nums[j] + 1000;
                dp[i][diff] =max(dp[i][diff], dp[j][diff]+1);
                result = max(result, dp[i][diff]);
            }
        }
        return result+1;
    }
};
