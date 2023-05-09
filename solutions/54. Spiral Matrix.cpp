class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, left = 0;
        int bottom = m-1, right = n-1;
        vector<int> result; 
        while (top<=bottom && left<=right) {
            for (int i=left; i<=right && top<=bottom; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;
            
            for (int i=top; i<=bottom && left<=right; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            
            for (int i=right; i>=left && top<=bottom; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
            
            for (int i=bottom; i>=top && left<=right; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        return result;
    }
    vector<int> spiralOrder1(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int r=0,c=0;
        int cdir = 0;
        int dist = 0;
        vector<int> result;
        while(rows>0 && cols>0)
        {
            result.push_back(matrix[r][c]);
            ++dist;
            if(cdir%2==0 && dist==cols)
            {
                ++cdir,rows-=1, dist=0;
            }
            else if(cdir%2==1 && dist==rows)
            {
                cdir= (cdir+1)%4,cols-=1, dist=0;
            }
            
            r += dir[cdir][0];
            c += dir[cdir][1];
        }
        return result;
    }
};
