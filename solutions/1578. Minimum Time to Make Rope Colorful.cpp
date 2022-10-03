class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int keep =neededTime[0];
        int total = keep;
        int result=0;
        for(int i=1;i<n;++i) {
            if(colors[i]!=colors[i-1]) {
                if(total != keep) 
                    result += total -keep;
                total = keep = neededTime[i];
            }
            else {
                total += neededTime[i];
                keep = max(keep,neededTime[i]);
            }
        }
        if(total != keep) 
            result += total -keep;
        return result;
    }
};
