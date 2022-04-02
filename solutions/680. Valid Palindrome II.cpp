class Solution {
public:
    bool validPalindrome1(string s) {
        int l=0,r=s.size()-1;
        while(l<r)
            if(s[l]==s[r])
                ++l,--r;
            else
                break;
        if(l>=r)
            return true;
        int l1=l+1;
        int r1=r;
        while(l1<r1)
            if(s[l1]==s[r1])
                ++l1,--r1;
            else
                break;
        if(l1>=r1)
            return true;
        l1=l;r1=r-1;
        while(l1<r1)
            if(s[l1]==s[r1])
                ++l1,--r1;
            else
                break;
        if(l1>=r1)
            return true;
        return false;
    }
    bool validPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j]) {
                int i1 = i, j1 = j - 1, i2 = i + 1, j2 = j;
                while (i1 < j1 && s[i1] == s[j1]) {i1++; j1--;};
                while (i2 < j2 && s[i2] == s[j2]) {i2++; j2--;};
                return i1 >= j1 || i2 >= j2;
            }
        return true;
    }
};
