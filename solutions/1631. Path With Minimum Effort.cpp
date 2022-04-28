class Solution {
public:
    // 280ms
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> visited(rows,vector(cols,false));
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<> > pq;
        pq.push({0,0});
        
        vector<vector<int>> dir{ {1,0},{0,1},{-1,0},{0,-1} };
        
        int result = 0;
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int r = p.second/cols;
            int c = p.second%cols;
            if(visited[r][c])  continue;
            visited[r][c] = true;
            if(r == rows-1 && c == cols-1)
            {
                result = d;
                break;
            }
            for(int i=0;i<4;++i)
            {
                int r1 = r + dir[i][0];
                int c1 = c + dir[i][1];
                if(r1<0 || r1>=rows || c1<0 || c1>=cols)    continue;
                   
                int newd = max(d, abs(heights[r1][c1]-heights[r][c]));
                pq.push({newd, r1*cols+c1});
            }
        }
        return result;
    }
};
