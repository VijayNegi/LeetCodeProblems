class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(begin(points),end(points));
        int prev = points[0][0];
        int result = 0;
        for(auto& p: points){
            result = max(result, p[0]-prev);
            prev = p[0];
        }
        return result;
    }
};
