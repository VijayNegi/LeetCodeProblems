class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows,vector(cols,false));
        function<bool(int,int)> dfs = [&](int r,int c){
            if(r<0 || r>=rows || c<0 || c>=cols)
                return false;
            if(grid[r][c] || visited[r][c]) return true;
            int dir[] = {0,-1,0,1,0};
            visited[r][c] = true;
            bool res = true;
            for(int i=0;i<4;++i){
                //if(!visited[r+dir[i]][c+dir[i+1]]);
                 res = dfs(r+dir[i],c+dir[i+1]) && res ;
            }
            return res;
        };
        int result=0;
        for(int i=0;i<rows;++i)
            for(int j=0;j<cols;++j){
                if(!grid[i][j] && !visited[i][j] && dfs(i,j))
                    ++result;
            }
        return result;
    }
};
