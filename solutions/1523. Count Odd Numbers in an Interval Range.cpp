class Solution {
public:
    int countOdds1(int low, int high) {
        int result=0;
        if(low&1){ ++low;++result;}
        if(high&1){--high;++result;}
        result += (high-low)/2;
        return result;
    }
     int countOdds(int low, int high) {
        return (high + 1) / 2 - low / 2;
    }
};
