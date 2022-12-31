class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr,sc;
        int rows = grid.size();
        int cols = grid[0].size();
        int visited=0;;
        for(int i=0;i<rows;++i)
            for(int j=0;j<cols;++j){
                if(grid[i][j]==1){
                    sr=i;sc=j;
                }
                else if(grid[i][j]==0)
                    ++visited;
            }
        int result = 0;
        ++visited;
        function<void(int,int)> dfs = [&](int r,int c){
            if(r<0 || r>=rows || c<0 || c>=cols || grid[r][c]>2 || grid[r][c]==-1)
                return;
            if(grid[r][c]==2){
                if(visited == 0)
                    ++result;
                return;
            }
            --visited;
            grid[r][c] = -1;
            vector<int> dir = {1,0,-1,0,1};
            for(int i=0;i<4;++i)
                dfs(r+dir[i],c+dir[i+1]);
            grid[r][c]=0;
            ++visited;
        };
        dfs(sr,sc);
        return result;
    }
};
