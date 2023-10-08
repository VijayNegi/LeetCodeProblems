class Solution {
public:
    int maxDotProduct1(vector<int>& nums1, vector<int>& nums2) {
        int result = numeric_limits<int>::min();
        int minv = numeric_limits<int>::min();
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> mem(n1,vector<int>(n2,minv));
        function<int(int,int)> dp = [&](int i,int j){
            if(i==n1 || j == n2)
                return minv;
            if(mem[i][j]!= minv) return mem[i][j];
            mem[i][j] = nums1[i]*nums2[j];
            if(dp(i+1,j+1) > 0) mem[i][j] += dp(i+1,j+1);
            mem[i][j] = max(mem[i][j], dp(i+1,j));
            mem[i][j] = max(mem[i][j], dp(i,j+1));
            
            return mem[i][j];
        };
        return dp(0,0);
    }
    // bottom up 
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = A[i] * B[j];
                if (i && j) dp[i][j] += max(dp[i - 1][j - 1], 0);
                if (i) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};
