class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result;
        if(original.size() != m*n) return result;
        result.resize(m,vector<int>(n,0));
        int k=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                result[i][j] = original[k++];
        return result;
    }
};
