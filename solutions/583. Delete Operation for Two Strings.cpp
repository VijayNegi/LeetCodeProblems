class Solution {
public:
    // DP: try to maintain a table of number of character that are matched till now
    // self : 61ms
    int minDistance1(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1,vector(n2,0));
        int result=0;
        for(int i=0;i<n1;++i) {
            for(int j=0;j<n2;++j) {
                if(word1[i]==word2[j])
                    ++dp[i][j];
                if(i>0 && j>0)
                    dp[i][j] += dp[i-1][j-1];
                if(j>0)
                    dp[i][j] = max(dp[i][j],dp[i][j-1]);
                if(i>0)
                    dp[i][j] = max(dp[i][j],dp[i-1][j]);
                //result = max(result,dp[i][j]);
            }
        }
        return n1+ n2- 2* dp[n1-1][n2-1];
    }
    // same as above
    // 35ms
    int minDistance2(string s1, string s2) {
         int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1+1,vector(n2+1,0));
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 || j == 0)
                    continue;
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return n1 + n2 - 2 * dp[n1][n2];
    }
    // count to char to delete
    // 35ms
    int minDistance3(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        for(int i=0 ;i<=word1.size();i++) {
            for(int j=0;j<=word2.size();j++) {
                if(i==0 || j== 0) {
                    dp[i][j]= i+j;
                }
                else if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i][j-1],dp[i-1][j]) +1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
    // space optimized
    // 44 ms
    int minDistance(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<int> dp(n2+1);
        for (int i = 0; i <= n1; i++) {
            vector<int> temp(n2+1);
            for (int j = 0; j <= n2; j++) {
                if (i == 0 || j == 0)
                    temp[j] = i + j;
                else if (s1[i - 1] == s2[j - 1])
                    temp[j] = dp[j - 1];
                else
                    temp[j] = 1 + min(dp[j], temp[j - 1]);
            }
            dp=temp;
        }
        return dp[s2.length()];
    }
};
