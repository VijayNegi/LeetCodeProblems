class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        auto& s = grid[0];
        for(int i=1;i<cols;++i)
            s[i]+= s[i-1];
        for(int i=1;i<rows;++i)
            for(int j=0;j<cols;++j){
                if(j==0)
                    s[0] += grid[i][0];
                else{
                    s[j] = min(s[j-1],s[j]) + grid[i][j];
                }
            }
        return s[cols-1];
    }
};
