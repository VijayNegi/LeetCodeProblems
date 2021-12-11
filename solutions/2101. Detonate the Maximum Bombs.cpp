typedef long long ll;
class Solution {
public:
    // Time complexity is O(n^3), because we start from n bombs and we can have upto O(n^2) edges.
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> ed(n);
        
        for(int i=0;i<n;++i)
        {
            ll r2 = (ll)bombs[i][2]*bombs[i][2];
            for(int j=i+1;j<n;++j)
            {
                int dx = abs(bombs[i][0] - bombs[j][0]);
                int dy = abs(bombs[i][1] - bombs[j][1]);
                long dis = (ll)dx*dx + (ll)dy*dy;
                if(dis <=  r2 )
                {
                    ed[i].push_back(j);
                }
                if(dis <=  (ll)bombs[j][2]*bombs[j][2] )
                {
                    ed[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n,false);
        function<int(int)> dfs = [&](int v)
        {
          if(visited[v])
              return 0;
            
            visited[v] = true;
            int count=1;
            for(auto& i:ed[v])
                count+= dfs(i);
            return count;
        };
        
        int maximum = 0;
        for(int i=0;i<n;++i)
        {
            fill(begin(visited),end(visited),false);
            maximum = max(dfs(i),maximum);
                
        }
        
        return maximum;
    }
};
