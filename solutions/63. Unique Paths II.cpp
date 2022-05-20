class Solution {
public:
    // dp n*n
    int uniquePathsWithObstacles1(vector<vector<int>>& obsG) {
        int rows = obsG.size();
        int cols = obsG[0].size();
        vector<vector<int>> dp(rows,vector(cols,0));
        if(obsG[0][0]==0)
            dp[0][0] = 1;
        for(int r= 0;r<rows;++r)
            for(int c=0;c<cols;++c)
            {
                if(obsG[r][c]==1)
                    continue;
                if(c-1>=0)
                    dp[r][c] += dp[r][c-1];
                 if(r-1>=0)
                    dp[r][c] += dp[r-1][c];
            }
        return dp[rows-1][cols-1];   
    }
    // dp n
     int uniquePathsWithObstacles(vector<vector<int>>& obsG) {
        int rows = obsG.size();
        int cols = obsG[0].size();
        vector<int> dp(cols,0);
        if(obsG[0][0]==0)
            dp[0] = 1;
        for(int r= 0;r<rows;++r)
            for(int c=0;c<cols;++c)
            {
                if(obsG[r][c]==1)
                    dp[c] = 0;
                else if(c-1>=0)
                    dp[c] += dp[c-1];
            }
        return dp[cols-1];   
    }
};
