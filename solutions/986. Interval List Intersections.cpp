// #include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstL, vector<vector<int>>& secondL) {
        int fl = firstL.size();
        int sl = secondL.size();
        vector<vector<int>> res;
        if(!fl or !sl)
            return res;
        
        sort(begin(firstL),end(firstL));
        sort(begin(secondL),end(secondL));
        
        int currf = 0;
        int currs = 0;
        
        
        while(currf < fl && currs < sl)
        {
            int s = max(firstL[currf][0],secondL[currs][0]);
            int e = min(firstL[currf][1],secondL[currs][1]);
            if(e-s>=0)
                res.push_back({s,e});
            if(e == firstL[currf][1])
                ++currf;
            if(e == secondL[currs][1])
                ++currs;
        }
        return res;
    }
};
