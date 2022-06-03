// class NumMatrix {
//     vector<vector<int>> mat;
// public:
//     NumMatrix(vector<vector<int>>& matrix) {
      
//         int rows = matrix.size();
//         int cols = matrix[0].size();
//         mat = vector<vector<int>>(rows+1,vector<int>(cols+1,0));
//         int rowsum=0;
//         for(int r=1;r<=rows;r++)
//         {
//             rowsum=0;
//             for(int c=1;c<=cols;c++)
//             {
//                 rowsum+=matrix[r-1][c-1];
//                 mat[r][c]= rowsum + mat[r-1][c];   
//             }
//         }
//     }
    
//     int sumRegion(int row1, int col1, int row2, int col2) {
//         return mat[row2+1][col2+1] - mat[row2+1][col1] - mat[row1][col2+1] +mat[row1][col1];
//     }
// };
​
class NumMatrix {
    vector<vector<int>> _mat;
    int rows,cols;
public:
    NumMatrix(vector<vector<int>>& matrix): _mat(matrix) {
        rows = _mat.size();
        cols = _mat[0].size();
        for(int i=0;i<rows;++i)
            for(int j=0;j<cols;++j) {
                if(i>0) _mat[i][j] += _mat[i-1][j];
                if(j>0) _mat[i][j] += _mat[i][j-1];
                if(i>0 && j>0) _mat[i][j] -= _mat[i-1][j-1];
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2,col2) - sum(row1-1,col2) - sum(row2,col1-1) + sum(row1-1,col1-1);
    }
    int sum(int row,int col) {
        if(row <0 || col <0)
            return 0;
        return _mat[row][col];
    }
};
​
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
