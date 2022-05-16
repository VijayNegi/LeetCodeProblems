using pi = pair<int,int>;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1)
            return -1;
        vector<vector<int>> dist(n,vector(n,INT_MAX));
        auto cmp = [&](pi left,pi right){
            if(dist[left.first][left.second] > dist[right.first][right.second])
                return true;
            return false;
        };
        //int dirx = { 1,1,1, 0, 0, -1,-1,-1};
        //int diry = {-1,0,1, 1,-1, -1, 0, 1};
        int dir[] = {1,1,0,1,-1,0,-1,-1,1};
        priority_queue<pi,vector<pi>,decltype(cmp)> pq(cmp);
        dist[0][0]=1;
        pq.push({0,0});
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            for(int i=0;i<8;++i) {
                int x = p.first + dir[i];
                int y = p.second + dir[i+1];
                if(x<0 || x>=n || y<0 || y>=n || grid[x][y]==1)
                    continue;
                
                if (dist[x][y]> (dist[p.first][p.second]+1)) {
                    dist[x][y] = dist[p.first][p.second]+1;
                    pq.push({x,y});
                }
            }
        }
        if(dist[n-1][n-1]==INT_MAX)
            return -1;
        return dist[n-1][n-1];
    }
};
