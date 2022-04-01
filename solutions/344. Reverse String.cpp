class Solution {
public:
    // stl
    void reverseString1(vector<char>& s) {
        reverse(begin(s),end(s));
    }
    // stl
    void reverseString(vector<char>& s) {
        int n = s.size();
        int l=0,r=n-1;
        while(l<r)
            swap(s[l++],s[r--]);
    }
};
