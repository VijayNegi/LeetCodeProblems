class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        if(n> s2.size()) return false;
        vector<int> hist1(26,0),hist2(26,0);
        for(auto& c:s1)
            hist1[c-'a']++;
        for(int i=0;i<n;++i)
            hist2[s2[i]-'a']++;
        if(hist1==hist2) return true;
        for(int i=n;i<s2.size();++i){
            hist2[s2[i]-'a']++;
            hist2[s2[i-n]-'a']--;
            if(hist1==hist2) return true;
        }
        return false;
    }
};
