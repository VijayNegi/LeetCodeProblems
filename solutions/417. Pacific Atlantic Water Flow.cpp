            reach[rows-1][c] |= 2;
        }
        for(int r=1;r<rows;++r)
        {
            for(int c=1;c<cols;++c)
            {
                if( ((heights[r][c] >= heights[r-1][c]) &&  (reach[r-1][c] & 1)   )  || ((heights[r][c] >= heights[r][c-1]) &&  (reach[r][c-1] & 1)  ) )
                    reach[r][c] |= 1;
            }
        }
        
        for(int r=rows-2;r>=0;--r)
        {
            for(int c=cols-2;c>=0;--c)
            {
                if( ((heights[r][c] >= heights[r+1][c]) &&  (reach[r+1][c] & 2)   )  || ((heights[r][c] >= heights[r][c+1]) &&  (reach[r][c+1] & 2)  ) )
                    reach[r][c] |= 2;
            }
        }
        
        vector<vector<int>> res;
        for(int r=0;r<rows;++r)
        {
            for(int c=0;c<cols;++c)
            {
                if(reach[r][c]==3)
                    res.push_back({r,c});
            }
        }
        
        return res;
    }
    // DFS : 269 ms
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> reachp(rows,vector(cols,false));
        vector<vector<bool>> reacha(rows,vector(cols,false));
        
        function<void(int,int,int, vector<vector<bool>>&)> dfs = [&](int r,int c,int val , vector<vector<bool>>& visited)
        {
            if(r<0 || c<0 || c>=cols || r>=rows || heights[r][c] < val ||  visited[r][c] == true)
                return;
            visited[r][c] = 1;
            vector<vector<int>> dir{{0,-1},{-1,0},{1,0},{0,1} };
            for(int i=0;i<4;++i)
            {
                int r1 = r + dir[i][0];
                int c1 = c + dir[i][1];
                dfs(r1,c1, heights[r][c],visited);
            }
        };
          
        for(int r=0;r<rows;++r)
        {
            dfs(r,0,0,reachp);
            dfs(r,cols-1,0,reacha);
        }
        
        for(int c=0;c<cols;++c)
        {
            dfs(0,c,0,reachp);
            dfs(rows-1,c,0,reacha);
        }
            
        vector<vector<int>> res;
        for(int r=0;r<rows;++r)
        {
            for(int c=0;c<cols;++c)
            {
                if(reacha[r][c]==1 && reachp[r][c]==1)
                    res.push_back({r,c});
            }
        }
        
        return res;
    }
};
