class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs),end(pairs));
        int end = numeric_limits<int>::min();
        int count = 0;
        for(auto& p:pairs){
            if(p[0] > end){
                ++count;
                end = p[1];
            }
            else
                end = min(end,p[1]);
        }
        return count;
    }
};
