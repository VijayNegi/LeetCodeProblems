class Solution {
public:
    int maxUncrossedLines1(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2=nums2.size();
        vector<vector<int>> dp(n1,vector(n2,-1));
        function<int(int,int)> solve = [&](int i,int j){
            if(i<0 || j<0) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            if(nums1[i]==nums2[j])
                dp[i][j] = 1+solve(i-1,j-1);
            else{
                dp[i][j] = max(solve(i-1,j),solve(i,j-1));
            }
            return dp[i][j];
        };
        return solve(n1-1,n2-1);
    }
    // Iterative
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
​
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
​
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
​
        return dp[n1][n2];
    }
};
