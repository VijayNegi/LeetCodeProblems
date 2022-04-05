class Solution {
public:
    int maxArea(vector<int>& height) {
        int result=0;
        int n = height.size();
        int l=0,r=n-1,maxh=0;
        while(l<r)
        {
            int h = min(height[l],height[r]);
            result = max(result,h*(r-l));
            maxh = max(maxh,h);
            if(height[l]<height[r])
                 while(l<r && height[l]<=maxh) ++l; 
            else
                 while(l<r && height[r]<=maxh) --r; 
​
        }
        return result;
    }
};
