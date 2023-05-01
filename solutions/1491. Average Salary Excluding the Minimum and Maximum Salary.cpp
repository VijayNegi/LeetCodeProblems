class Solution {
public:
    double average(vector<int>& salary) {
        int low=INT_MAX,high = 0;
        double sum=0;
        for(auto& s:salary){
            low = min(s,low);
            high = max(s,high);
            sum += s;
        }
        return (sum-low-high)/(salary.size()-2);
    }
};
