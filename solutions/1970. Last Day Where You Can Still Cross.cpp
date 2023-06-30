        // fill left and right with water
        for(int i=0;i<rows;++i)
            grid[i][0] = grid[i][cols-1] = 1;
        DSU dset(rows*cols);
        vector<int> dir{1,0,-1,0,1};
        for(int r=0;r<rows;++r){
            for(int c=0;c<cols;++c){
                for(int i=0;i<4;++i){
                    int r1 = r+dir[i];
                    int c1 = c+dir[i+1];
                    if(r1<0 || r1>=rows || c1<0 || c1>=cols) 
                        continue;
                    if(grid[r1][c1]==0)
                        dset.merge(cols*r+c,cols*r1+c1);
                }
            }
        }
        // check if we can reach from top to bottom
        if(dset.find(0)== dset.find(cols*(rows-1)))
            return n;
        for(int i=n-1;i>=0;--i){
            int r = cells[i][0];
            int c = cells[i][1];
            grid[r][c] = 0;
            for(int i=0;i<4;++i){
                int r1 = r+dir[i];
                int c1 = c+dir[i+1];
                // if(r1<0 || r1>=rows || c1<0 || c1>=cols) 
                //     continue;
                if(grid[r1][c1]==0)
                    dset.merge(cols*r+c,cols*r1+c1);
            }
            // check if we can reach from top to bottom
            if(dset.find(0)== dset.find(cols*(rows-1)))
                return i;
            }
        return 0;
    }
};
