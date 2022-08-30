class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int s = matrix.size();
        //int cols = matrix.size();
        
        for(int r=0;r<(s)/2;++r){
            for(int c = r; c<(s-r-1);++c) {
                int val = matrix[r][c];
                matrix[r][c] = matrix[s-1-c][r];
                matrix[s-1-c][r] = matrix[s-r-1][s-1-c];
                matrix[s-r-1][s-1-c] = matrix[c][s-r-1];
                matrix[c][s-r-1] = val;
            }
        }
    }
};
​
