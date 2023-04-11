class Solution {
public:
    string removeStars(string s) {
        int l=0,r=0,n=s.size();
        for(int i=0;i<n;++i){
            if(s[i]!='*')
                s[l++]=s[i];
            else
                --l;
        }
        s.resize(l);
        return s;
    }
};
