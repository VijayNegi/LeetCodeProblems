class Solution {
public:
    // self
    int countSubstrings1(string s) {
        int n =s.size();
        int result=0;
        for(int i=0;i<n;++i) {
            int l,r;
            l=r=i;
            while(l>=0 && r<n && s[l--]==s[r++]) {
                ++result;
            }
        }
        for(int i=0;i<n-1;++i) {
            int l,r;
            l=i;
            r=l+1;
            while(l>=0 && r<n && s[l--]==s[r++]) {
                ++result;
            }
        }
        return result;
    }
    int countSubstrings(string s) {
        int counter = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                counter++;
            }
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                counter++;
            }
        }
        return counter;
    }
};
