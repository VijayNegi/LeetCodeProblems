class Solution {
public:
    vector<vector<int>> kClosest1(vector<vector<int>>& points, int k) {
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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partial_sort(points.begin(), points.begin() + K, points.end(), [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
    vector<vector<int>> kClosest2(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K - 1, points.end(), [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
