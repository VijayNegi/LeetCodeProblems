class Solution {
public:
    bool validPalindrome1(string s) {
        int n = s.size();
        int i=0,j=n-1;
        int k=1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                ++i;--j;
            }
            else if(k>0)
                ++i,--k;
            else 
                break;
                
        }
        if(i>=j)
            return true;
        i=0,j=n-1,k=1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                ++i;--j;
            }
           else if(k>0)
                --j,--k;
            else 
                break;
        }
        if(i>=j)
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
