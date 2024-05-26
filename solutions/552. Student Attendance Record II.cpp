const int mod = 1e9+7;
class Solution {
public:
    // self , but TLE not sure why
    int checkRecord1(int n) {
        unordered_map<int,int> dp;
        function<int(int, int,int)> dfs = [&](int k,int ab, int late){
            if(k==0) return 1;
            int key = (k<<3) + (late << 1) + ab;
            if(dp[key] != 0) return dp[key];
            int sum = dfs(k-1, ab,2); // preset
             sum %= mod;
            if(ab)  sum += dfs(k-1, 0,2); // ab
            sum %= mod;
            if(late) sum += dfs(k-1, ab,late-1); // late
            sum %= mod;
            return dp[key] = sum;
        };
        
        return dfs(n,1,2);
    }
        int MOD = 1000000007;
        vector<vector<vector<int>>> memo;
​
        int eligibleCombinations(int n, int totalAbsences, int consecutiveLates) {
​
            if (totalAbsences >= 2 or consecutiveLates >= 3) {
                return 0;
            }
            if (n == 0) {
                return 1;
            }
            if (memo[n][totalAbsences][consecutiveLates] != -1) 
                return memo[n][totalAbsences][consecutiveLates];
​
            int count = 0;
            // We choose 'P' for the current position.
            count = eligibleCombinations(n - 1, totalAbsences, 0);
            // We choose 'A' for the current position.
            count = (count + eligibleCombinations(n - 1, totalAbsences + 1, 0)) % MOD;
            // We choose 'L' for the current position.
            count = (count + eligibleCombinations(n - 1, totalAbsences, consecutiveLates + 1)) % MOD;
​
            return memo[n][totalAbsences][consecutiveLates] = count;
        }
​
        int checkRecord(int n) {
           
            memo = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
            return eligibleCombinations(n, 0, 0);
        }
};
