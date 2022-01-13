class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ar = 0;
        int preEnd = points[0][1];
        for(auto& b:points)
        {
            if(b[0] <= preEnd)
            {
                preEnd = min(preEnd, b[1]);
                continue;
            }
            ++ar;
            preEnd = b[1];
        }
        ++ar;
        return ar;
    }
};
