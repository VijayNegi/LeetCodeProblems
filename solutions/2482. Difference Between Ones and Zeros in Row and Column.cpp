class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> oR(rows,0),oC(cols,0),zR(rows,0),zC(cols,0);
        for(int r=0;r<rows;++r){
            for(int c=0;c<cols;++c){
                if(grid[r][c])
                    oR[r]++,oC[c]++;
                else
                    zR[r]++,zC[c]++;
            }
        }
        
        for(int r=0;r<rows;++r){
            for(int c=0;c<cols;++c){
                grid[r][c] = oR[r]+oC[c]-zR[r]-zC[c];
            }
        }
        return grid;
    }
};
