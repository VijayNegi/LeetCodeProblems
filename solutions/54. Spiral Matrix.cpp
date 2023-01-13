class Solution {
public:
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
    // https://leetcode.com/problems/spiral-matrix/discuss/978853/C%2B%2B-or-0ms-faster-than-100-or-Easy-solution-with-proper-explanation
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0,right=m-1,bottom=n-1,top=0;
        int direction=1;
        vector<int> v;
        while(left<=right && top<=bottom)
        {
            if(direction==1)
            {
                for(int i=left;i<=right;i++) v.push_back(matrix[top][i]);
                direction=2;
                top++;
            }
            
            else if(direction==2)
            {
                for(int i=top;i<=bottom;i++) v.push_back(matrix[i][right]);
                direction=3;
                right--;
            }
            
            else if(direction==3)
            {
                for(int i=right;i>=left;i--) v.push_back(matrix[bottom][i]);
                direction=4;
                bottom--;
            }
            
            else if(direction==4)
            {
                for(int i=bottom;i>=top;i--) v.push_back(matrix[i][left]);
                direction=1;
                left++;
            }
        }
        return v;
        
    }
};
