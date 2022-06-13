class Solution {
public:
    // 16ms
    int minimumTotal1(vector<vector<int>>& triangle) {
        int n = triangle.size();
        //vector<int> res = triangle[0];
        for(int i=1;i<n;++i) {
            triangle[i][0] += triangle[i-1][0];
            for(int j=1;j<i;++j) {
                triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);
            }
            triangle[i][i] += triangle[i-1][i-1];
        }
        return *min_element(triangle[n-1].begin(),triangle[n-1].end());
    }
    // old solution: 8ms
    int minimumTotal(vector<vector<int>>& triangle) {
        int size= triangle.size();
        vector<int> result(size,INT_MAX);
        result[0]=triangle[0][0];
        for(int i=1;i<size;i++) {
            for(int j=triangle[i].size()-1;j>=0;j--) {
                result[j] = min(result[j],(j>0)?result[j-1]:INT_MAX);
                result[j]+= triangle[i][j];
            }
        }
        int minTotal=INT_MAX;
        for(const auto& num:result) 
            minTotal = min(minTotal,num);
        return minTotal;
    }
};
