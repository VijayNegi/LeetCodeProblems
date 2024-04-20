class Solution {
public:
    // self
    vector<vector<int>> findFarmland1(vector<vector<int>>& land) {
        vector<vector<int>> result;
        int rows = land.size();
        int cols = land[0].size();
        for(int i=0;i<rows;++i){
            int s = 0;
            for(int j=0;j<cols;++j){
                if(i!=0 && land[i][j]) land[i][j] += land[i-1][j];
                if(land[i][j]) ++s;
                else if(s && (i== rows-1 || (land[i+1][j-1]!= 1 ))){
                    result.push_back({i-land[i][j-1] +1 , j - s , i,j-1 });
                }
                if(!land[i][j])  s=0;
            }
            if(s && (i== rows-1 || (land[i+1][cols-1]!= 1 ))) 
                result.push_back({ i- land[i][cols-1] +1 , cols - s, i,cols-1 });
​
        }
        return result;
    }
    // https://leetcode.com/problems/find-all-groups-of-farmland/discuss/1451820/Mark-Left-Side
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int m = land.size(), n = land[0].size();
    vector<vector<int>> res;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (land[i][j] == 1) {
                int x = i, y = j;
                while (y < n && land[i][y])
                    ++y;                
                for (; x < m && land[x][j]; ++x)
                    land[x][j] = y - j + 1;
                res.push_back({i, j, x - 1, y - 1});
            }
            if (land[i][j] > 1)
                j += land[i][j] - 1;
        }
    return res;
}  
};
