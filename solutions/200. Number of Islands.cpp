class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        function<void(int,int)> dfs = [&](int r,int c)
        {
            if(r<0 || c<0 || r>=rows || c>=cols)
                return;
            if(grid[r][c]=='1')
            {
                grid[r][c] = '#';
                dfs(r+1,c);
                dfs(r-1,c);
                dfs(r,c+1);
                dfs(r,c-1);
            }
        };
        int result=0;
        for(int i=0;i<rows;++i)
            for(int j=0;j<cols;++j)
                if(grid[i][j]=='1')
                    ++result, dfs(i,j);
        return result;
        
    }
};
