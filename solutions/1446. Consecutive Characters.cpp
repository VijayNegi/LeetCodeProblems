class Solution {
public:
    int maxPower(string s) {
        char p = 0;
        int power = 0;
        int currP = 0;
        
        for(auto c: s)
        {
            if(p == c)
                ++currP;
            else
            {
                power = max(power,currP);
                currP = 1;
                p = c;
            }
        }
        power = max(power,currP);
        return power;
    }
};
