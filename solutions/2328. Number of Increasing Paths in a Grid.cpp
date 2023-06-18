const int mod = 1e9+7;
class Solution {
public:
    // bfs: TLE
    int countPaths1(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> que;
        for(int r=0;r<rows;r++)
            for(int c=0;c<cols;c++){
                que.push_back({r,c});
            }
        long result=0;
        function<bool(int,int)> isValid = [&](int r,int c){
            if(r<0 || r>=rows || c<0 || c>=cols)
                return false;
            return true;
        };
        vector<int> dir{1,0,-1,0,1};
        while(que.size()){
            result += que.size();
            result %= mod;
            vector<vector<int>> temp;
            for(auto& pos:que){
                for(int i=0;i<4;++i){
                    int r1 = pos[0]+dir[i], c1 = pos[1]+dir[i+1];
                    if(isValid(r1,c1)){
                        if(grid[r1][c1]>grid[pos[0]][pos[1]])
                            temp.push_back({r1,c1});
                    }
                }
                    
            }
            swap(que,temp);
        }
        return result;
    }
    // dfs
    int countPaths(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows,vector(cols,-1));
        long result=0;
        function<bool(int,int)> isValid = [&](int r,int c){
            if(r<0 || r>=rows || c<0 || c>=cols)
                return false;
            return true;
        };
        vector<int> dir{1,0,-1,0,1};
        function<int(int,int)> dfs = [&](int r,int c){
            if(dp[r][c]!= -1) return dp[r][c];
            long res=1;
            for(int i=0;i<4;++i){
                int r1 = r+dir[i], c1 = c+dir[i+1];
                if(isValid(r1,c1) && grid[r1][c1]>grid[r][c]){
                    res += dfs(r1,c1);
                    res %= mod;
                }
            }
            return dp[r][c] = res;
        };
        for(int r=0;r<rows;r++)
            for(int c=0;c<cols;c++){
                result += dfs(r,c);
                result %= mod;
            }
        return result;
    }
};
