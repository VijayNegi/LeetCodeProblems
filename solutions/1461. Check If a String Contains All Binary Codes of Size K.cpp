class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>=s.size())
            return false;
        int mask=0;
        int count = 1<<k;
        int number=0;
        for(int i=1;i<=k;++i) {
            mask = mask<<1;
            mask |= 1;
        }
        unordered_set<int> st;
        for(int i=0;i<k;++i) {
            number = number <<1;
            number = number | (s[i]=='0'?0:1);
        }
        st.insert(number);
        for(int i=k;i<s.size();++i) {
            number = number <<1;
            number = number | (s[i]=='0'?0:1);
            number &= mask;
            st.insert(number);
        }
        return st.size()==count; 
    }
};
