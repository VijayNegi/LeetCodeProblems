class Solution {
public:
    // self : have issues
    int stoneGameII1(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector(n,0));
        function<int(int,int)> f = [&](int pos,int m){
            if(pos>=n) return 0;
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
    int stoneGameII(vector<int>& piles) {
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
};
