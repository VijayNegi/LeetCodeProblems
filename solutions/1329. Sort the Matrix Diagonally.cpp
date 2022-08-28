class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        for(int c=0;c<cols;++c){
            int c1 = c,r1=0;
            vector<int> vec;
            while(c1<cols && r1<rows) 
                vec.push_back(mat[r1++][c1++]);
            sort(vec.begin(),vec.end());
            c1 = c,r1=0;
            for(auto& v:vec)
                mat[r1++][c1++] = v;
        }
        
        for(int r=0;r<rows;++r){
            int c1 = 0,r1=r;
            vector<int> vec;
            while(c1<cols && r1<rows) 
                vec.push_back(mat[r1++][c1++]);
            sort(vec.begin(),vec.end());
            c1 = 0,r1=r;
            for(auto& v:vec)
                mat[r1++][c1++] = v;
        }
        return mat;
    }
};
​
