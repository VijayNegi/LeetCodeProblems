class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>& l, vector<int>& r){return l[1]>r[1];});
        int count=0;
        for(auto& b:boxTypes) {
            int c = min(b[0],truckSize);
            count += b[1]*c;
            truckSize-=c;
            if(truckSize==0)
                break;
        }
        return count;
    }
};
