class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
    int fmin = 0, smin = 0, pos = -1;
    for (auto i = 0; i < arr.size(); ++i) {
        auto fmin2 = INT_MAX, smin2 = INT_MAX, pos2 = -1;
        for (auto j = 0; j < arr[i].size(); ++j) {
            auto mn = j != pos ? fmin : smin;
            if (arr[i][j] + mn < fmin2) {
                smin2 = fmin2;
                fmin2 = arr[i][j] + mn;
                pos2 = j;
            } else smin2 = min(smin2, arr[i][j] + mn);
        }
        fmin = fmin2, smin = smin2, pos = pos2;
    }
    return fmin;
}
};
