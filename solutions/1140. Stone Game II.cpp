            if(dp[pos][m]>0) return dp[pos][m];
            //dp[pos][m]=0;
            if(n-pos <=  2*m) {
                for(int i=pos;i<n;++i)
                    dp[pos][m]+= piles[i];
                return dp[pos][m];
            }
            int sum=0;
            int maxAlt=0;
            for(int i=pos;i<(pos+2*m);++i){
                sum += piles[pos];
                int s = f(i+1,max(pos-i+1,m));
                if(sum+s> dp[pos][m]){
                    dp[pos][m] = sum+s;
                    maxAlt = dp[i+1][max(pos-i+1,m)];
                }
                
                //maxAlt = max(maxAlt,dp[i+1][max(pos-i+1,m)]);
            }
            return maxAlt;
        };
        f(0,1);
        return dp[0][1];
    }
    //https://leetcode.com/problems/stone-game-ii/discuss/345247/C%2B%2B-DP-(Tabulation)
    int stoneGameII2(vector<int>& piles) {
        int length = piles.size();
        vector<vector<int>>dp(length + 1, vector<int>(length + 1,0));
        vector<int> sufsum (length + 1, 0);
        for (int i = length - 1; i >= 0; i--) {
            sufsum[i] = sufsum[i + 1] + piles[i];
        }
        for (int i = 0; i <= length; i++) {
            dp[i][length] = sufsum[i];
        }
        for (int i = length - 1; i >= 0; i--) {
            for (int j = length - 1; j >= 1; j--) {
                for (int X = 1; X <= 2 * j && i + X <= length; X++) {
                    dp[i][j] = max(dp[i][j], sufsum[i] - dp[i + X][max(j, X)]);
                }
            }
        }
        return dp[0][1];
    }
    // official solution
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector dp(2, vector(n + 1, vector<int>(n + 1, -1)));
        
        function<int(int, int, int)> f = [&](int p, int i, int m) -> int {
            if (i == n) {
                return 0;
            }
            if (dp[p][i][m] != -1) {
                return dp[p][i][m];
            }
            int res = p == 1 ? 1000000 : -1, s = 0;
            for (int x = 1; x <= min(2 * m, n - i); x++) {
                s += piles[i + x - 1];
                if (p == 0) {
                    res = max(res, s + f(1, i + x, max(m, x)));
                }
                else {
                    res = min(res, f(0, i + x, max(m, x)));
                }
            }
            return dp[p][i][m] = res;
        };
        
        return f(0, 0, 1);
    }
};
