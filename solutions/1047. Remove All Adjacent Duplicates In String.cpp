class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        int l,r;
        l=0,r=1;
        while(r<n){
            if(l>=0 && s[l] == s[r]){
                --l,++r;
                continue;
            }  
            s[++l] = s[r++];
        }
        s.resize(l+1);
        return s;
    }
};
