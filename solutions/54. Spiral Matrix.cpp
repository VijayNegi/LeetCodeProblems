class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
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
