class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows,cols;
        rows = matrix.size();
        cols = matrix[0].size();
        
        int r,c;
        r = 0;
        c= cols-1;
        
        while(r<rows && c>=0)
        {
            if(target == matrix[r][c])
                return true;
            else if(target > matrix[r][c])
                ++r;
            else
                --c;
        }
        
        return false;
    }
};
