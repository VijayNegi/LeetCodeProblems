class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int s = rows*cols;
        k = k%(s);
        
        vector<vector<int>> result(rows,vector(cols,0));
        
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                int pos = i*cols+j+k;
                pos %= s;
                result[pos/cols][pos%cols] = grid[i][j];
            }
        }
        return result;
    }
};
