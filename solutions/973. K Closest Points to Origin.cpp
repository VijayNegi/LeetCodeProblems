class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<pair<int,int>> dist(n);
        for(int i=0;i<n;++i)
        {
            int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            dist[i] = make_pair(d,i);
        }
        sort(dist.begin(),dist.end());
        vector<vector<int>> result;
        for(int i=0;i<k;++i)
        {
            result.push_back(points[dist[i].second]);
        }
        return result;
    }
};
