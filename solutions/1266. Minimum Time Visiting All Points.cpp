class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result=0;
        int n = points.size();
        for(int i=1;i<n;++i){
            result += max(abs(points[i][0] - points[i-1][0]),abs(points[i][1] - points[i-1][1]) );
        }
        return result;
    }
};
