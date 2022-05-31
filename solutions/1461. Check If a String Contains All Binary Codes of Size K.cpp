class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>=s.size())
            return false;
        
        int count = 1<<k;
        int mask= count-1;
        int number=0;
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
