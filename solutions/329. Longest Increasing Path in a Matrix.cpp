class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int dir[] = {0,1,0,-1,0};
        vector<vector<int>> path(rows,vector(cols,-1));
        
        function<int(int,int,int)> dfs = [&](int r,int c,int pre) {
            if(pre >= matrix[r][c])
                return 0;
            if(path[r][c]!= -1)
                return path[r][c];
            int plength = 0;
            for(int i=0;i<4;++i)
            {
                int r1 = r+dir[i];
                int c1 = c+dir[i+1];
                if(r1<0 || c1<0 || r1>=rows || c1>= cols)
                    continue;
                plength = max(plength, dfs(r1,c1,matrix[r][c]));
            }
            return path[r][c] = ++plength;
        };
        
        int result{0};
        for(int r=0;r<rows;++r)
            for(int c=0;c<cols;++c)
            {
                result = max(result,dfs(r,c,-1));
            }
        return result;
    }
};
