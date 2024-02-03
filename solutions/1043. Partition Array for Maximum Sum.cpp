class Solution {
public:
    // self : top down
    int maxSumAfterPartitioning1(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        function<int(int)> dfs = [&](int p){
            if(p>=n) return 0;
            if(dp[p]>=0) return dp[p];
            int m=0;
            for(int i=p;i<n and i<p+k;++i){
                m = max(m,arr[i]);
                dp[p] = max(m*(i-p+1) + dfs(i+1), dp[p]);
            }
            return dp[p];
        };
        return dfs(0);
    }
    // bottom up
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int N = arr.size();
​
        int dp[N + 1];
        memset(dp, 0, sizeof(dp));
        
        for (int start = N - 1; start >= 0; start--) {
            int currMax = 0;
            int end = min(N, start + k);
​
            for (int i = start; i < end; i++) {
                currMax = max(currMax, arr[i]);
                // Store the maximum of all options for the current subarray.
                dp[start] = max(dp[start], dp[i + 1] + currMax * (i - start + 1));
            }
        }
        return dp[0];
    }
};
