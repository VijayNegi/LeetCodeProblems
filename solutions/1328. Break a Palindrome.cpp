class Solution {
public:
    // self
    string breakPalindrome1(string p) {
        int n = p.size();
        if(n<=1)
            return "";
        bool odd = n%2;
        int i=0;
        for(i=0;i<n;++i) {
            if(odd && i==n/2)
                continue;
            if(p[i]!='a'){
                p[i]='a';
                break;
            }  
        }
        if(i==n)
            p.back()++;
        return p;
    }
    // optimized
    string breakPalindrome(string S) {
        int n = S.size();
        for (int i = 0; i < n / 2; ++i) {
            if (S[i] != 'a') {
                S[i] = 'a';
                return S;
            }
        }
        S[n - 1] = 'b';
        return n < 2 ? "" : S;
    }
};
