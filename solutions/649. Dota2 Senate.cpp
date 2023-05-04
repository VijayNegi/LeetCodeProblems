class Solution {
public:
    // self
    string predictPartyVictory1(string senate) {
        int rd=0,rr=0;
        int s= senate.size();
        while(true){
            int l=0,r=0;
            int ss =s;
            while(r<ss){
                if(senate[r]=='R'){
                   if(rr) --rr,--s;
                    else {
                        senate[l++] = senate[r];
                        ++rd;
                    }
                }
                else{
                    if(rd) --rd,--s;
                    else {
                        senate[l++] = senate[r];
                        ++rr;
                    }
                }
                ++r;
            }
            if(ss ==s)
                break;
        }
        if(senate[0]=='R') return "Radiant";
        return "Dire";
    }
    // Official solution
    string predictPartyVictory(string senate) {

        int rCount = 0, dCount = 0;
        int dFloatingBan = 0, rFloatingBan = 0;

        queue<char> q;
        for (char c : senate) {
            q.push(c);
            if (c == 'R') rCount++;
            else dCount++;
        }

        while (rCount && dCount) {
            char curr = q.front();
            q.pop();

            if (curr == 'D') {
                if (dFloatingBan) {
                    dFloatingBan--;
                    dCount--;
                } else {
                    rFloatingBan++;
                    q.push('D');
                }
            } else {
                if (rFloatingBan) {
                    rFloatingBan--;
                    rCount--;
                } else {
                    dFloatingBan++;
                    q.push('R');
                }
            }
        }
        return rCount ? "Radiant" : "Dire";
    }

};
