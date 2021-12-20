class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        int s = arr.size();
        sort(arr.begin(),arr.end());
        
        int minDiff = INT_MAX;
        vector<vector<int>> res;
        for(int i=0;i<s-1;++i)
        {
            int diff = arr[i+1] - arr[i];
            if( diff < minDiff )
            {
                minDiff = diff;
                res.clear();
                res.push_back({arr[i],arr[i+1]});
            }
            else if(diff == minDiff)
            {
                res.push_back({arr[i],arr[i+1]});
            }
        }
        
        return res;
    }
};
