class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int row=1;row<rows;++row){
            for(int col=0;col<cols;++col){
                int l= col-1<0?0:col-1;
                int r = col+1>=cols?cols-1:col+1;
                int val = INT_MAX;
                while(l<=r){
                    val = min(val,matrix[row-1][l++]);
                }
                matrix[row][col] +=val;
            }
        }
        return *min_element(matrix[rows-1].begin(),matrix[rows-1].end());
    }
};
