int mat[300][300];
class Solution {
public:
    int maximalSquare1(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxMat = 0;
        for(int r=0;r<rows;++r)
        {
            for(int c=0;c<cols;++c)
            {
                mat[r][c] = (matrix[r][c] == '1');
                if(mat[r][c] && (r!=0 && c!=0))
                {
                    int tm = min(mat[r-1][c], min(mat[r-1][c-1],mat[r][c-1]));
                    mat[r][c] += tm;
                }
                maxMat = max(maxMat,mat[r][c]);
            }
        }
        return maxMat*maxMat;
        
    }
    // space optimization
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int> dp(cols+1,0);
        int maxMat = 0;
        int pre = 0;
        for(int r=0;r<rows;++r)
        {
            for(int c=0;c<cols;++c)
            {
                int temp = dp[c];
                if((matrix[r][c] == '1') &&  c!=0)
                {
                    dp[c] = min(dp[c], min(dp[c-1], pre)) + 1;
                }
                else
                    dp[c] = (matrix[r][c] == '1');
                maxMat = max(maxMat,dp[c]);
                pre = temp;
            }
        }
        return maxMat*maxMat;
        
    }
};
