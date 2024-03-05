class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        while(l<r){
            if(s[l]!= s[r]) break;
            int ll = l;
            while(s[ll] == s[l] && ll<r)
                ++ll;
            if(ll == r) return 0;
            int rr = r;
            while(s[rr] == s[r] && rr>ll)
                --rr;
            l = ll;
            r = rr;
        }
        return r-l+1;
    }
};
