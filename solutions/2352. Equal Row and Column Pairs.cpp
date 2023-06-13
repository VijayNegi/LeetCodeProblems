class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string,int> seen;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0;i<rows;++i){
            string r;
            for(int j=0;j<cols;++j)
                r += to_string(grid[i][j])+",";
            seen[r]++;
        }
        int result = 0;
        for(int j=0;j<cols;++j){
            string r;
            for(int i=0;i<rows;++i)
                r += to_string(grid[i][j])+",";
            result += seen[r];
        }
        return result;
    }
};
