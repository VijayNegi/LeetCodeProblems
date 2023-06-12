class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if(n==0) return result;
        int start,end;
        start=end= nums[0];
        for(int i=1;i<n;++i){
            if(nums[i]!= end +1){
                if(start == end)
                    result.push_back(to_string(start));
                else
                    result.push_back(to_string(start) + "->"+ to_string(end));
                start = end = nums[i];
            }
            else
                end++;
        }
        if(start == end)
            result.push_back(to_string(start));
        else
            result.push_back(to_string(start) + "->"+ to_string(end));
        return result;
    }
};
