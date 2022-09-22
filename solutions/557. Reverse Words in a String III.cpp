class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string::size_type pos=0;
        while(pos < n) {
            int next = s.find(' ',pos);
            if(next ==string::npos)
                 next = n;
            auto st =s.begin();
            auto ed =s.begin();
            advance(st,pos);
            advance(ed,next);
            reverse(st,ed);
            pos = next+1;
        }
        return s;
    }
};
