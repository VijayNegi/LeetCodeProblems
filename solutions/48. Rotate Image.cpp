class Solution {
public:
    void rotate1(vector<vector<int>>& matrix) {
        int s = matrix.size();
        //int cols = matrix.size();
        
        for(int r=0;r<(s)/2;++r){
            for(int c = r; c<(s-r-1);++c) {
                int val = matrix[r][c];
                matrix[r][c] = matrix[s-1-c][r];
                matrix[s-1-c][r] = matrix[s-1-r][s-1-c];
                matrix[s-1-r][s-1-c] = matrix[c][s-r-1];
                matrix[c][s-r-1] = val;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for(int row = 0; row < n/2; row++)
            for(int col = row; col < n - row - 1; col++)
            {                
                swap(matrix[row][col], matrix[col][n - 1 - row]);
                swap(matrix[row][col], matrix[n - 1 - row][n - 1 - col]);
                swap(matrix[row][col], matrix[n - 1 - col][row]);
            }
    }
};
​
