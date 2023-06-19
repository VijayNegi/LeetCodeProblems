class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result=0;
        int curr=0;
        for(auto l:gain){
            curr += l;
            result = max(result,curr);
        }
        return result;
    }
};
