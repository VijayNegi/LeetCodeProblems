using pi = pair<int,int>;
class Solution {
public:
    // 49/52 test cases
    // dfs has issue with with using visited grid with memo, 
    // as it can happen the visiting from different direction can corrupt memo state
    int shortestPath1(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int dir[] = {0,1,0,-1,0};//{1,0,-1,0,1};
        vector<vector<vector<int>>> memo(rows,vector(cols,vector(k+1,-1)));
        vector<vector<int>> vis(rows,vector(cols,0));
        function<int(int,int,int)> dfs = [&](int r,int c,int kk) {
            // if(vis[r][c])
            //     return INT_MAX;
            if(r==rows-1 && c==cols-1)
                return 0;
            if(memo[r][c][kk] != -1)
                return memo[r][c][kk];
            int m=INT_MAX;
            vis[r][c]=1;
            for(int i=0;i<4;++i) {
                int r1 = r+dir[i];
                int c1 = c+dir[i+1];
                if(r1<0 || r1==rows || c1<0 || c1==cols || vis[r1][c1])
                    continue;
                if(grid[r1][c1]==0)
                    m = min(m,dfs(r1,c1,kk));
                if(grid[r1][c1] && kk>0) {
                    m = min(m,dfs(r1,c1,kk-1));
                }
            }
            vis[r][c]=0;
            memo[r][c][kk] = (m ==INT_MAX)? m : m+1;
            //cout<<r<<" "<<c<<" "<<memo[r][c][kk]<<endl;
            return memo[r][c][kk];
        };
        int result = dfs(0,0,k);
        return result==INT_MAX? -1:result;
    }
    
    // https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/712992/C%2B%2B-or-BFS
    int solve(vector<vector<int>>& grid,int k){
        int rows = grid.size();
        int cols = grid[0].size();
        // At a particular cell we will store the number of obstacles that we can still remove after walking through that cell
        vector<vector<int>> vis(rows,vector<int>(cols,-1));
        queue<vector<int>> q;
        
        // queue stores (x,y,current path length,number of obstacles we can still remove)
        q.push({0,0,0,k});
        while(!q.empty()){
            auto t=q.front();
            int x=t[0],y=t[1];
            q.pop();
            
            // Exit if current position is outside of the grid
            if(x<0 || y<0 || x>=rows || y>=cols){
                continue;
            }
            
            // Destination found
            if(x==grid.size()-1 && y==cols-1)
                return t[2];
