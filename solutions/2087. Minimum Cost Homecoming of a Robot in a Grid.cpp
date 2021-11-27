class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int cost = 0;
        
        if(startPos[0]==homePos[0] && startPos[1]==homePos[1])
            return cost;
        while(startPos[0]!=homePos[0])
        {
            startPos[0] +=  homePos[0]>startPos[0] ? +1 : -1;
            cost+= rowCosts[startPos[0]];
        }
        while(startPos[1]!=homePos[1])
        {
            startPos[1] += homePos[1]>startPos[1] ? +1 : -1;
            cost+= colCosts[startPos[1]];
        }
        return cost;
    }
};
