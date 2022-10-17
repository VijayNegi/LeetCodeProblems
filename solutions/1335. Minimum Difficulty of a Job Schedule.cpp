class Solution {
public:
    // self: bottom-up : 97 ms
    // complexity : O(nnd) 
    int minDifficulty1(vector<int>& jd, int d) {
        int n = jd.size();
        if(n<d) return -1;
        if(n==d) 
            return accumulate(begin(jd),end(jd),0);
        vector<vector<int>> dp(d+1,vector(n,INT_MAX));
        // fill for 1 day case 
        // dp[x][y]   x - days , y- from this index
        dp[1][n-1] = jd[n-1];
        for(int i=n-2;i>=0;--i) {
            dp[1][i] = max(jd[i],dp[1][i+1]);
        }
        
        for(int k=2;k<=d;++k) {
            //cout<<"day-"<<k<<endl<<endl;
            int currmax = 0;
            for(int i=0;i<(n-k+1);++i) {
                currmax = jd[i];
                //cout<<"start-"<<i<<" value- "<<currmax<<endl;
                for(int j=i+1;j<(n-k+2);++j) {
                    dp[k][i] = min(dp[k][i], currmax+ dp[k-1][j]);
                    //cout<<"partition "<<j<<" -- "<<currmax+ dp[k-1][j]<< "      "; 
                    currmax = max(currmax,jd[j]);
                }
                //cout<<endl;
            }
        }
        return dp[d][0];
    }
    // https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/discuss/490316/JavaC%2B%2BPython3-DP-O(nd)-Solution
    // 1d DP : 46 ms
    int minDifficulty2(vector<int>& A, int D) {
        int n = A.size(), inf = 1e9, maxd;
        if (n < D) return -1;
        vector<int> dp(n + 1, 1e9);
        dp[n] = 0;
        for (int d = 1; d <= D; ++d) {
            for (int i = 0; i <= n - d; ++i) {
                maxd = 0, dp[i] = inf;
                for (int j = i; j <= n - d; ++j) {
                    maxd = max(maxd, A[j]);
                    dp[i] = min(dp[i], maxd + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
    // https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/discuss/490316/JavaC%2B%2BPython3-DP-O(nd)-Solution
    // stack based soution
    // 9 ms
    int minDifficulty(vector<int>& A, int D) {
        int n = A.size();
        if (n < D) return -1;
        vector<int> dp(n, 1000), dp2(n), stack;
        for (int d = 0; d < D; ++d) {
            stack.clear();
            for (int i = d; i < n; i++) {
                dp2[i] = i ? dp[i - 1] + A[i] : A[i];
                while (stack.size() && A[stack.back()] <= A[i]) {
                    int j = stack.back(); stack.pop_back();
                    dp2[i] = min(dp2[i], dp2[j] - A[j] + A[i]);
                }
                if (stack.size()) {
                    dp2[i] = min(dp2[i], dp2[stack.back()]);
                }
                stack.push_back(i);
            }
            swap(dp, dp2);
        }
        return dp[n - 1];
    }
};
