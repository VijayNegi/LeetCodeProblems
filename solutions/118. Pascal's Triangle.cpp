class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        result[0].push_back(1);
        for(int i=1;i<numRows;++i) {
            for(int j=0;j<=i;++j) {
                if(j==0 || j==i)
                    result[i].push_back(1);
                else {
                    result[i].push_back(result[i-1][j]+ result[i-1][j-1]);
                }
            }
        }
        return result;
    }
};
