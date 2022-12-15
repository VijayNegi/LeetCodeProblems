class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.size();
        int t2 = text2.size();
        vector<vector<int>> dp(t1+1,vector(t2+1,0));
        for(int i=0;i<t1;++i){
            for(int j=0;j<t2;++j){
                if(text1[i]==text2[j])
                    dp[i+1][j+1] = dp[i][j]+1;
                else 
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[t1][t2];
    }
};
