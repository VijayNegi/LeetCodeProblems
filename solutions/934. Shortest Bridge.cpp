class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n,vector(n,false));
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        
        list<pair<int,int>> border;
        // find first island and mark it visited;
        function<void(int,int)> first = [&](int r,int c)
        {
            if(visited[r][c])
                return;
            if(grid[r][c]==0)
            {
                border.push_back({r,c});
                visited[r][c] = true;
                return;
            }
                
            visited[r][c] = true; // mark visited;
            for(int dir=0;dir<4;++dir)
            {
                int rr = r+dx[dir];
                int cc = c+dy[dir];
                if(rr<0 || rr>=n) continue;
                if(cc<0 || cc>=n) continue;
                
                first(rr,cc);
            }
            return;
        };
        bool found =false;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1 )
                {
                    first(i,j);
                    found= true;
                    break;
                }   
            }
            if(found)
                break;
        }
        // expand the found island till we meet the second islannd
        int dist=1;
        while(!border.empty())
        {
            list<pair<int,int>> temp;
            
            for(auto p:border)
            {
                for(int dir=0;dir<4;++dir)
                {
                    int rr = p.first+dx[dir];
                    int cc = p.second+dy[dir];
                    if(rr<0 || rr>=n) continue;
                    if(cc<0 || cc>=n) continue;
                    if(visited[rr][cc]) continue;
                    if(grid[rr][cc] == 1)
                        return dist;
                    temp.push_back({rr,cc});
                    visited[rr][cc] = true;
                }
            }
            
            border = temp;
            ++dist;
        }
        return 0;
    }
};
