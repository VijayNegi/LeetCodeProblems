class Solution {
public:
    int removePalindromeSub(string s) {
        int r = s.size()-1;
        int l=0;
        while(l<r) {
            if(s[l]==s[r])
                ++l,--r;
            else
                break;
        }
        if(l>=r)
            return 1;
        return 2;
    }
};
