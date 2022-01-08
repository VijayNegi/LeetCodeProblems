class Solution {
public:
    // dp top down : 91 ms , note few restrictions
    int cherryPickup1(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));
        
        function<int(int,int,int)> dfs = [&](int r,int c1, int c2){
            if(r == rows || c1<0 || c2==cols || c1>=c2)
                return 0;
            if(dp[r][c1][c2]>=0)
                return dp[r][c1][c2];
            int result = 0;
            
            for(int i = c1-1; i<=c1+1;i++)
                for(int j = c2-1;j<=c2+1;j++)
                    result = max(result, dfs(r+1,i,j));
                
            result += grid[r][c1] + grid[r][c2];
            dp[r][c1][c2] = result;
            return result;
        };
        
        return dfs(0,0,cols-1);
    }
    // dp bottom up : 101 ms 
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));
        
        
        for(int r=rows-1;r>=0;--r)
        {
            for(int c1=0;c1<cols-1;++c1)
            {
                for(int c2 = c1+1;c2<cols;++c2)
                {
                    if(r==rows-1)
                    {
                        dp[r][c1][c2] = grid[r][c1] + grid[r][c2];
                    }
                    else
                    {
                        int minC = max(c1-1,0);
                        int maxC = min(c2+1,cols-1);
                        int result = 0;
                        
                        for(int i = c1-1; i<=c1+1;i++)
                            for(int j = c2-1;j<=c2+1;j++)
                            {
                                if(i<0 || j>=cols || i>=j)
                                    continue;
                                result = max(result, dp[r+1][i][j]);
                            }
                               
                        dp[r][c1][c2] =  grid[r][c1] + grid[r][c2] + result;
                    }
                }
            }
        }
        
        return dp[0][0][cols-1];
    }
};
