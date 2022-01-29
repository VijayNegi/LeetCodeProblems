        {
            int area = mqueue.back().second * (n-mqueue.back().first);
            mqueue.pop_back();
            result = max(result,area);
        }
        return result;
    }
    // mono stack again but somewhat cleaner : 361ms
    int largestRectangleArea2(vector<int>& heights) {
        list<int> s;
        int n= heights.size();
        int result=0;
        for(int i=0;i<n;++i)
        { 
            
            while(!s.empty() && heights[s.back()] >= heights[i])
            {
                int H = heights[s.back()];
                s.pop_back();
                int W =  (s.empty()? i: i- s.back()-1);
                result = max(result,H*W);
            }
            s.push_back(i);
        }
        while(!s.empty())
        {
            int H = heights[s.back()];
            s.pop_back();
            int W =(s.empty()? n: n- s.back()-1);
            result = max(result,H*W);
        }
        return result;
    }
    
    // dp - https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28902/5ms-O(n)-Java-solution-explained-(beats-96)
    // 195 ms
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> lessFromLeft(n,0); // idx of the first bar the left that is lower than current
        vector<int> lessFromRight(n,0); // idx of the first bar the right that is lower than current
        
        lessFromRight[n - 1] = n;
        lessFromLeft[0] = -1;
​
        for (int i = 1; i < n; i++) {
            int p = i - 1;
​
            while (p >= 0 && heights[p] >= heights[i]) {
                p = lessFromLeft[p];
            }
            lessFromLeft[i] = p;
        }
​
        for (int i = n - 2; i >= 0; i--) {
            int p = i + 1;
​
            while (p < n && heights[p] >= heights[i]) {
                p = lessFromRight[p];
            }
            lessFromRight[i] = p;
        }
​
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, heights[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
        }
​
        return maxArea;
    }
};
