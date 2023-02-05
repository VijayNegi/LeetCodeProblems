class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        vector<int> result;
        if(n> s.size()) return result;
        vector<int> hist1(26,0),hist2(26,0);
        for(auto& c:p)
            hist1[c-'a']++;
        for(int i=0;i<n;++i)
            hist2[s[i]-'a']++;
        if(hist1==hist2) result.push_back(0);
        for(int i=n;i<s.size();++i){
            hist2[s[i]-'a']++;
            hist2[s[i-n]-'a']--;
            if(hist1==hist2) result.push_back(i-n+1);
        }
        return result;
    }
};
