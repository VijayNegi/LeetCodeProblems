class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        function<int(int,int)> dfs = [&](int i,int j){
            if(i<0 || j<0 || i>=r || j>=c || (grid[i][j] == 0))
                return 0;
            int result=grid[i][j];
            grid[i][j]=0;
            return result + dfs(i+1,j) + dfs(i-1,j) + dfs(i,j-1) +dfs(i,j+1);
        };
        int result = 0;
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                if(grid[i][j])
                    result = max(result,dfs(i,j));
        return result;
    }
};
