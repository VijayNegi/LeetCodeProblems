class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int len = coordinates.size();
        int x,x1,y,y1;
        if(len==2)
            return true;
​
        x=coordinates[0][0];
        y=coordinates[0][1];
        x1=coordinates[1][0];
        y1=coordinates[1][1];
        int num = y1-y;
        int den = x1-x;
        for (size_t i = 1; i < len; i++)        
        {
            x1=coordinates[i][0];
            y1=coordinates[i][1];
            int tnum = y1-y;
            int tden = x1-x;
            if(num*tden != den*tnum)
                return false;
        }
        return true;
    }
};
