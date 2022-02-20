class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](vector<int>& left,vector<int>& right){ 
            if(left[0]== right[0]) 
                return left[1]>right[1];
            return left[0] < right[0];
        };
        sort(begin(intervals),end(intervals),cmp);
        int n = intervals.size();
        int removed = 0;
        int right = intervals[0][1];
        for(int i=1;i<n;++i)
        {
            if(intervals[i][1]<= right)
                ++removed;
            else
                right = intervals[i][1];
        }
        return n - removed;
    }
};
