class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int result=0;
        int n = grid.size();
        auto isValid = [&](int r,int c)-> bool{
            if(r<0 || r>=n || c<0 || c>=n) return false;
            return true;
        };
        vector<pair<int,int>> ones;
        for(int r=0;r<n;++r)
                for(int c=0;c<n;++c)
                    if(grid[r][c]==1) ones.push_back({r,c});
        if(ones.empty()) return -1;
        if(ones.size() == n*n) return -1;
        vector<int> dir{1,0,-1,0,1};
        while(ones.size()){
            vector<pair<int,int>> temp;
            for(auto [r,c]:ones){
                for(int i=0;i<4;++i){
                    if(isValid(r+dir[i],c+dir[i+1]) && grid[r+dir[i]][c+dir[i+1]] == 0){
                        temp.push_back({r+dir[i],c+dir[i+1]});
                        grid[r+dir[i]][c+dir[i+1]] = 1;
                    }
                }
            }
            swap(ones,temp);
            ++result;
        }
        return result-1;
    }
};
