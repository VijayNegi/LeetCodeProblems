const int mod = 1e9 + 7;
class Solution {
public:
    // self :12 ms
    int rectangleArea(vector<vector<int>>& rectangles) {
        long area=0;
        int n = rectangles.size();
        sort(begin(rectangles),end(rectangles)); // sort with start of x
        int currx=0; // curr x coordinate we are procesing
        int rectid=0;   // rect id to process 
        auto cmp = [&](int l,int r) {return rectangles[l][2]>rectangles[r][2];};
        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp); // pq with rect id sorted in ending order
        unordered_set<int> currRects; // set of rect id we are currently processing
        while(true) {
            // remove any rect id that we have already processed i.e. currx has crossed it
            while(pq.size() && rectangles[pq.top()][2] <= currx ) {
                currRects.erase(pq.top());
                pq.pop();
            }
            // if no active processing rect then pick next one from list
            if(pq.empty() && rectid<n) {
                currx = rectangles[rectid][0];
                currRects.insert(rectid);
                pq.push(rectid++);
            }
            
            if(pq.empty())  // still empty? nothing to process further
                break;
            
            int maxx = rectangles[pq.top()][2];     // find the next x till to process area
            if(rectid<n)
                maxx = min(rectangles[rectid][0],maxx);     // do not start any new rect;
            
            vector<pair<int,int>> yseg;     // find all the segments in y direction within curr x bounds
            long maxy = 0;
            for(auto i:currRects) {
                yseg.push_back({rectangles[i][1],rectangles[i][3]});
            }
            sort(begin(yseg),end(yseg));
            int y=-1;
            // merge all segments and find sum of segment length
            for(auto s:yseg) {
                if(y<s.second) {
                    maxy += s.second - max(s.first,y);
                    y = s.second;
                }
            }
            // calculate area for current bounds
            long size = (maxx- currx) * maxy;
            area += size;
            currx = maxx ;
            // add rectangles that have started to the queue
            while(rectid <n && rectangles[rectid][0] <= currx) {
                currRects.insert(rectid);
                pq.push(rectid++);
            }
        }
        return area%mod;
    }
};

