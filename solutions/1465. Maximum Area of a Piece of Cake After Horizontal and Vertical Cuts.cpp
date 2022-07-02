const int mod = 1e9+7;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
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
};
