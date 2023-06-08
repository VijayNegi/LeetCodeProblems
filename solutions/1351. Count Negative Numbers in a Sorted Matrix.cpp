class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int r = 0;
        int c = cols-1;
        int result=0;
        while(r<rows){
            while(c>=0){
                if(grid[r][c]>=0)
                    break;
                --c;
            }
            result += cols-c-1;
            ++r;
        }
        return result;
    }
};
