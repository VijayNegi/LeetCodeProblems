                return;
            if(isupper(grid[r][c]) && ((1<<(grid[r][c]-'A')) & k))
                return;
            visited[r][c][0] = min(visited[r][c][0],path);
            visited[r][c][1] = visited[r][c][1] | k;
            if(islower(grid[r][c])){
                k  = k | (1<<(grid[r][c]-'a'));
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
​
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
