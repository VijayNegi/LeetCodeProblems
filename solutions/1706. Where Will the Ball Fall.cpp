class Solution {
public:
    // dfs : 23ms
    // consider ball as deflected as light not as roll and determine next column and row
    vector<int> findBall(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> result(cols,-1);
        
        for(int c=0;c<cols;++c) {
            int c1 = c;
            int r1 = 0;
            for(;r1<rows;++r1) {
                if(grid[r1][c1] == 1) {
                    if(c1<cols-1 && grid[r1][c1+1]== 1)
                        ++c1;
                    else break;
                }
                else if(grid[r1][c1] == -1) {
                    if(c1>0 && grid[r1][c1-1]==-1)
                        --c1;
                    else break;
                }
            }
            if(r1==rows)
                result[c] = c1;
        }
        return result;
    }
};
