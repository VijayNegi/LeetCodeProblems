class Solution {
public:
    // 167 ms
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int n = height.size();
        int l = 0;
        int r = n-1;
        int containerHeightSeen = 0;
        while(l<r)
        {
            int h = min(height[l],height[r]);
            int water = h*(r-l);
            maxWater = max(maxWater,water);
            containerHeightSeen = max(h,containerHeightSeen);
            if(height[l]<height[r])
                while(l<r && height[l]<=containerHeightSeen) ++l;
            else
                while(r>l && height[r]<=containerHeightSeen) --r;
        }
        
        return maxWater;
    }
};
