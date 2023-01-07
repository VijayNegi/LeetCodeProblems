class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int station=0,mingas=0,currgas=0;
        for(int i=0;i<gas.size();++i){
            if(currgas<mingas){
                station=i;
                mingas=currgas;
            }
            currgas += gas[i]-cost[i];
        }
        if(currgas<0)
            return -1;
        return station;
    }
};
