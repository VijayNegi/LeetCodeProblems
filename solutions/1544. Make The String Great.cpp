class Solution {
public:
    string makeGood(string s) {
        int l=0,r=1;
        while(r<s.size()) {
            if(l<0)
                s[++l] = s[r++];
            else if((tolower(s[l]) == tolower(s[r])) && s[l]!=s[r]) 
                       --l,++r;
            else
                   s[++l] = s[r++];
        }
        s.resize(l+1);
        return s;
    }
};
