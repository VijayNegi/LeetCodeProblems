class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        int c=cols-1,r=0;
        while(r<rows && c>=0)
        {
            if(matrix[r][c] ==target)
                return true;
            else if(matrix[r][c] > target)
                --c;
            else
                ++r;
        }
        return false;
    }
};
