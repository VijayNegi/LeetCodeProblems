class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int obstacles = 0;
        for(int r=0;r<rows;++r)
        {
            obstacles += std::count(grid[r].cbegin(), grid[r].cend(), -1);
        }
        int walks = rows * cols - obstacles -2;
        int currwalks = 0;
        int paths = 0;
        //cout<<"obs="<<obstacles<<endl;
        
        const function<void(int,int)> dfs = [&](int r,int c)
        {
            if(r<0 || c<0 || r==rows || c==cols || grid[r][c]==-1 )
                return;
            
            if(grid[r][c]==2)
            {
                if(currwalks == walks+1)
                    ++paths;
                return;
            }
            grid[r][c] = -1;
            ++currwalks;
            dfs(r+1,c);
            dfs(r,c+1);
            dfs(r-1,c);
            dfs(r,c-1);
            --currwalks;
            grid[r][c] = 0;
                
        };
        
        for(int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if(grid[r][c]==1)
                {
                    dfs(r,c);
                    return paths;
                }
            }
        }
        return paths;
    }
};
