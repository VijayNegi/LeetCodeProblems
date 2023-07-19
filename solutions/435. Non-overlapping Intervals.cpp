class Solution {
public:
    // self 505ms
    int eraseOverlapIntervals1(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>& l,vector<int>& r){if(l[0]==r[0]) return l[1]>r[1];
                                                                                return l[0]<r[0];});
        int result = 0;
        int lastEnd = std::numeric_limits<int>::min()+1;
        for(auto& interval:intervals){
            if(interval[0]>=lastEnd){
                lastEnd = interval[1];
            }
            else{
                lastEnd = min(lastEnd,interval[1]);
                ++result;
            }
        }
        return result;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int result = 0;
        int lastEnd = std::numeric_limits<int>::min();
        for(auto& interval:intervals){
            if(interval[0]>=lastEnd){
                lastEnd = interval[1];
            }
            else{
                lastEnd = min(lastEnd,interval[1]);
                ++result;
            }
        }
        return result;
    }
};
