class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> histogram(26,0);
        for(char c: s)
        {
            c-='a';
            histogram[c]++;
        }
        for(char c:t)
        {
            c-='a';
            histogram[c]--;
        }
        for(int i:histogram)
            if(i!=0)
                return false;
        return true;
    }
};
