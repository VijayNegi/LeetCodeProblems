const int mod = 1e9+7;
class Solution {
public:
    // self :141 ms
    int maxArea1(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int mh=0,mv=0,pre=0;
        for(auto& c:horizontalCuts) {
            mh = max(mh, c-pre);
            pre = c;
        }
        mh = max(mh, h-pre);
        pre =0;
        for(auto& c:verticalCuts) {
            mv = max(mv, c-pre);
            pre = c;
        }
        mv = max(mv, w-pre);
        long area = (long)mh * mv;
        return area%mod;
    }
    // clean : 126 ms
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        sort(begin(hCuts), end(hCuts));
        sort(begin(vCuts), end(vCuts));
        auto max_h = max(hCuts[0], h - hCuts.back());
        auto max_v = max(vCuts[0], w - vCuts.back());
        for (auto i = 0; i < hCuts.size() - 1; ++i)
            max_h = max(max_h, hCuts[i + 1] - hCuts[i]);
        for (auto i = 0; i < vCuts.size() - 1; ++i)
            max_v = max(max_v, vCuts[i + 1] - vCuts[i]);        
        return (long)max_h * max_v % mod;
    }
};
