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
            if(ab)  sum += dfs(k-1, 0,2); // ab
            sum %= mod;
            if(late) sum += dfs(k-1, ab,late-1); // late
            sum %= mod;
            return dp[key] = sum;
        };
        
        return dfs(n,1,2);
    }
        int MOD = 1000000007;
        vector<vector<vector<int>>> memo;

        int eligibleCombinations(int n, int totalAbsences, int consecutiveLates) {

            if (totalAbsences >= 2 or consecutiveLates >= 3) {
                return 0;
            }
            if (n == 0) {
                return 1;
            }
            if (memo[n][totalAbsences][consecutiveLates] != -1) 
                return memo[n][totalAbsences][consecutiveLates];

            int count = 0;
            // We choose 'P' for the current position.
            count = eligibleCombinations(n - 1, totalAbsences, 0);
            // We choose 'A' for the current position.
            count = (count + eligibleCombinations(n - 1, totalAbsences + 1, 0)) % MOD;
            // We choose 'L' for the current position.
            count = (count + eligibleCombinations(n - 1, totalAbsences, consecutiveLates + 1)) % MOD;

            return memo[n][totalAbsences][consecutiveLates] = count;
        }

        int checkRecord2(int n) {
           
            memo = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
            return eligibleCombinations(n, 0, 0);
        }
    // https://leetcode.com/problems/student-attendance-record-ii/discuss/101643/Share-my-O(n)-C%2B%2B-DP-solution-with-thinking-process-and-explanation
    int checkRecord(int n) {
        int m = 1000000007;
        int *A = new int [n+2];
        int *P = new int [n+2];
        int *L = new int [n+2];
        
        P[0] = 1;
        L[0] = 1;
        L[1] = 3;
        A[0] = 1;
        A[1] = 2;
        A[2] = 4;
        
        if(n == 1) return 3;
        
        for(int i = 1; i < n; i++)
        {
            A[i - 1] %= m;
            P[i - 1] %= m;
            L[i - 1] %= m;
            
            P[i] = ((A[i - 1] + P[i - 1]) % m + L[i - 1]) % m;
            
            if(i > 1) L[i] = ((A[i - 1] + P[i - 1]) % m + (A[i - 2] + P[i - 2]) % m) % m;
            
            if(i > 2) A[i] = ((A[i - 1] + A[i - 2]) % m + A[i - 3]) % m;
        }
        
        return ((A[n - 1] % m + P[n - 1] % m) % m + L[n - 1] % m) % m;
    }
};
