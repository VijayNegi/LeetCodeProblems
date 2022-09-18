class Solution {
public:
    // monotonic stack
    int trap0(vector<int>& height) {
        int n = height.size();
        vector<int> stk;
        int result=0;
        for(int i=0;i<n;++i) {
            int h=0; // height already processed
            while(stk.size() ) {
                int minh = min(height[stk.back()], height[i]);
                int height1 =  minh-h;
                int width = i- stk.back() -1;
                int area = width * (height1);
                result += area;
                h = max(h, minh);
                if((height[stk.back()] <= height[i]))
                    stk.pop_back();
                else break;
            }
            if(height[i]>0)
                stk.push_back(i);
        }
        return result;
    }
    // Two way
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<3)
            return 0;
        vector<int> LeftMax(n,0);
        vector<int> RightMax(n,0);
        
        LeftMax[0] = height[0];
        for(int i=1;i<n;++i)
        {
            LeftMax[i] = max(LeftMax[i-1],height[i]);
        }
        RightMax[n-1] = height[n-1];
        for(int i=n-2;i>=0;--i)
        {
            RightMax[i] = max(RightMax[i+1],height[i]);
        }
        int result = 0;
