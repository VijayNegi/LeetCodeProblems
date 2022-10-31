class Solution {
public:
    // self: 50 ms
    bool isToeplitzMatrix1(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int r=1;r<rows;++r)
            for(int c=1;c<cols;++c){
                if(r>=c){
                    int r1 = r-c;
                    if(matrix[r][c] != matrix[r1][0])
                        return false;
                }
                else{
                    int c1 = c-r;
                    if(matrix[r][c] != matrix[0][c1])
                        return false;
                }
            }
        return true;
    }
    // solution : 31ms
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int r=1;r<rows;++r)
            for(int c=1;c<cols;++c)
                if(matrix[r][c] != matrix[r-1][c-1])
                    return false;
        return true;
    }
};
