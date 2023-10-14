class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> memo(n, vector(n + 1, -1));
        function<int(int, int)> dp = [&](int i,int remain)-> int{
            if (remain <= 0) return 0;
            if (i == n) return 1e9;
        
            if (memo[i][remain] != -1) 
                return memo[i][remain];
            
            int paint = cost[i] + dp(i + 1, remain - 1 - time[i]);
            int dontPaint = dp(i + 1, remain);
            memo[i][remain] = min(paint, dontPaint);
            return memo[i][remain];
        };
        return dp(0, n);
    }
};
​
