class Solution {
public:
    // self
    bool winnerOfGame1(string colors) {
        int aMoves=0,bMoves=0;
        int aCount=0,bCount=0;
        for(auto& c: colors){
            if(c=='A'){
                aCount++;
                if(bCount>2) bMoves += bCount-2;
                bCount = 0;
            }
            else{
                bCount++;
                if(aCount>2) aMoves += aCount-2;
                aCount = 0;
            }
        }
        if(aCount>2) aMoves += aCount-2;
        if(bCount>2) bMoves += bCount-2;
        if(aMoves>bMoves) return true;
        return false;
    }
​
    bool winnerOfGame(string colors) {
        int alice = 0;
        int bob = 0;
        
        for (int i = 1; i < colors.size() - 1; i++) {
            if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
                if (colors[i] == 'A') {
                    alice++;
                } else {
                    bob++;
                }
            }
        }
        
        return alice > bob;
    }
​
};
