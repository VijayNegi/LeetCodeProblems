class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int m = grid.size(); // rows
        int n = grid[0].size();
        
        for(int i=0;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                if(grid[i][j])
                    grid[i][j]+= grid[i][j-1];
            }
        }
        int pyd = 0;
        
        auto isValid = [&](int i,int j) -> bool
        {
            if(i>=0 && i < m && j>=0 && j<n)
                return true;
            return false;
        };
        
        for(int i=0;i<m;++i)
        {
            for(int j=2;j<n;++j)
            {
                if(grid[i][j] >= 3)
                {
                    //check for pyd
                    int r = i,c = j;
                    int len = grid[i][j];
                    while(isValid(r-1,c-1))
                    {
                        --r,--c;
                        len -= 2;
                        len = min(grid[r][c],len);
                        if(len<=0)
                            break;
                        ++pyd;
​
                    }
                    // check for re pyd
                    r = i,c = j;
                    len = grid[i][j];
                    while(isValid(r+1,c-1))
                    {
                        ++r,--c;
                        len -= 2;
                        len = min(grid[r][c],len);
                         if(len<=0)
                            break;
                        ++pyd;
​
                    }
                }
            }
        }
        return pyd;
        
    }
};
