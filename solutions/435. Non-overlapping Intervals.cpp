class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(begin(intervals),end(intervals));
        int res=0;
        int last = intervals[0][1];
        for(int i=1;i<n;++i)
        {
            if(last <= intervals[i][0])
                last = intervals[i][1];
            else
            {
                last = min(last,intervals[i][1]);
                ++res; // remove the current or previous
            }
                
        }
        return res;
    }
};
