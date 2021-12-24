class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> res;
        res.push_back(intervals.front());
        for(int i=1;i<n;++i)
        {
            auto& vec = intervals[i];
            auto& curr = res.back();
            
            if(curr[1]>= vec[0])
            {
                curr[1] = max(vec[1],curr[1]);
            }
            else
            {
                res.push_back(vec);
            }
        }
        
        return res;
    }
};
