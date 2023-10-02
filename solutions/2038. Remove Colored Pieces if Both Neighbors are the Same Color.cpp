class Solution {
public:
    bool winnerOfGame(string colors) {
        int aMoves=0,bMoves=0;
        int aCount=0,bCount=0;
        for(auto& c: colors){
            if(c=='A'){
                aCount++;
                if(bCount>2)
                    bMoves += bCount-2;
                bCount = 0;
            }
            else{
                bCount++;
                if(aCount>2)
                    aMoves += aCount-2;
                aCount = 0;
            }
        }
        if(aCount>2)
            aMoves += aCount-2;
        if(bCount>2)
            bMoves += bCount-2;
        if(aMoves>bMoves) return true;
        return false;
    }
};
