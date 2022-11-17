class Solution {
public:
    // line sweep or total - common
    int computeArea1(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area = abs((ax2-ax1)*(ay2-ay1)) + abs((bx2-bx1)*(by2-by1));
        int xtotal = abs(ax2-ax1) + abs(bx2-bx1);
        int ytotal = abs(ay2-ay1) + abs(by2-by1);
        bool xoverlap = abs(bx2-ax1) < xtotal && abs(ax2-bx1) < xtotal;
        bool yoverlap = abs(ay2-by1) < ytotal && abs(by2-ay1) < ytotal;
​
        if(xoverlap && yoverlap){
            int common = (max(ax1,bx1) - min(ax2,bx2))*(max(ay1,by1) - min(ay2,by2));
            area -= common;
        }
        return area;
    }
    int computeArea2(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        int x = min(G, C) > max(E, A) ? (min(G, C) - max(E, A)) : 0;
        int y = min(D, H) > max(B, F) ? (min(D, H) - max(B, F)) : 0;
        return (D - B) * (C - A) + (G - E) * (H - F) - x * y;
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
        // sum of areas of two rectangles minus the area of their intersection
        return (ax2 - ax1) * (ay2 - ay1) + 
             (bx2 - bx1) * (by2 - by1) - 
             max(min(ax2,bx2) - max(ax1,bx1),0) * max(min(ay2,by2) - max(ay1,by1),0);
    }
};
​
​
