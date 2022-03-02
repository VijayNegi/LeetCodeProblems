class Solution {
public:
​
    bool isSubsequence(string s, string t) {
        int sn = s.size();
        int tn = t.size();
        int is = 0,it=0;
        while(is<sn && it<tn)
        {
            if(s[is]==t[it])
                ++is,++it;
            else
                ++it;
        }
        if(is==sn)
            return true;
        return false;
    }
};
