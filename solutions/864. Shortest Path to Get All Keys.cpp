class Solution {
public:

    // my code have some issue with visited 
    int shortestPathAllKeys1(vector<string>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int keys=0,sr,sc;
        vector<vector<vector<int>>> visited(rows,vector(cols, vector(2,0)));
        // get starting position and count for keys
        for(int r=0;r<rows;++r){
            for(int c=0;c<cols;++c){
                if(islower(grid[r][c]))
                    ++keys;
                else if(grid[r][c]=='@'){
                    sr = r;
                    sc = c;
                }
                visited[r][c][0] = numeric_limits<int>::max();
            }
        }
        auto is_valid = [&](int r,int c){
            if(r<0 || r>= rows || c<0 || c>=cols)
                return false;
            return true;
        };
        vector<int> dir{0,1,0,-1,0};
        int maxKeys = (1<<(keys))-1;
        //int kfound=0;
        int result=numeric_limits<int>::max();
        
        function<void(int,int,int,int )> dfs = [&](int r,int c, int path,int k){
            if(grid[r][c]=='#') return;
            if(visited[r][c][0]<= path && ((visited[r][c][1] | k) == visited[r][c][1]))
                return;
            if(isupper(grid[r][c]) && ((1<<(grid[r][c]-'A')) & k))
                return;
            visited[r][c][0] = min(visited[r][c][0],path);
            visited[r][c][1] = visited[r][c][1] | k;
            if(islower(grid[r][c])){
                k  = k | (1<<(grid[r][c]-'a'));
                if(k==maxKeys)
                    result = min(result,path);
            }
            for(int i=0;i<4;++i){
                if(is_valid(r+dir[i],c+dir[i+1])){
                    dfs(r+dir[i],c+dir[i+1],path+1,k);
                }
            }
            //kfound.erase(grid[r][c]);
        };
        dfs(sr,sc,0,0);
        if(result == numeric_limits<int>::max()) return -1;
        return result;                                   
    }
    // https://leetcode.com/problems/shortest-path-to-get-all-keys/discuss/146941/C%2B%2B-BFS-with-current-key-recorded-visited-map-(12ms)
    int shortestPathAllKeys(vector<string>& grid) {
    int m=grid.size(), n=m?grid[0].size():0;
    if(!m || !n) return 0;
    int path=0, K=0;
    vector<int> dirs={0,-1,0,1,0};
    vector<vector<vector<bool>>> visited(m,vector<vector<bool>>(n,vector<bool>(64,0))); //at most 6 keys, using bitmap 111111
    queue<pair<int,int>> q; //<postion, hold keys mapping>
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='@'){
                q.push({i*n+j,0});
                visited[i][j][0]=1;                    
            }
            if(grid[i][j]>='A' && grid[i][j]<='F') K++; //total alpha number
        }
    }
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int a=q.front().first/n, b=q.front().first%n;
            int carry=q.front().second;
            q.pop();        
            if(carry==((1<<K)-1)) return path; //if all keys hold, just return 
            for(int j=0;j<4;j++){
                int x=a+dirs[j], y=b+dirs[j+1], k=carry;
                if(x<0 || x>=m || y<0 || y>=n || grid[x][y]=='#') continue;
                if(grid[x][y]>='a' && grid[x][y]<='f'){
                    k=carry|(1<<(grid[x][y]-'a')); //update hold keys
                }
                else if(grid[x][y]>='A' && grid[x][y]<='F'){
                    if(!(carry & (1<<(grid[x][y]-'A')))) continue;
                }
                if(!visited[x][y][k]){
                    visited[x][y][k]=1;
                    q.push({x*n+y,k});
               }                
            }
        }
        path++;
    }
    return -1;
}
};
