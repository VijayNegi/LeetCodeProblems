class Solution {
public:
    // BFS: 205 ms
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();
        
        function<bool(int,int)> isValid = [&](int r,int c){
            if(r<0 || c<0 || r>=rows || c>=cols || maze[r][c]!='.' )
                return false;
            return true;
        };
        function<bool(int,int)> isBorder = [&](int r,int c){
            if(r == 0 || c==0 || r==(rows-1) || c==(cols-1 ))
                return true;
            return false;
        };
        vector<int> dir{1,0,-1,0,1};
        //vector<vector<bool>> visited(rows,vector(cols,false));
        int level=-1;
        vector<vector<int>> queue{entrance};
        maze[entrance[0]][entrance[1]] = 'v';
        while(queue.size()){
            vector<vector<int>> temp;
            for(auto& p:queue){
                if(level>=0 && isBorder(p[0],p[1]))
                   return level+1;
                for(int i=0;i<4;++i){
                    if(isValid(p[0]+dir[i],p[1]+dir[i+1]) ){
                        temp.push_back({p[0]+dir[i],p[1]+dir[i+1]});
                        maze[p[0]+dir[i]][p[1]+dir[i+1]] = 'v';
                    }
                }
            }
            queue = temp;
            ++level;
        }
        return -1;
    }
};
