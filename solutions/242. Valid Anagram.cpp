class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> hist(26,0);
        for(auto& c:s)
            hist[c-'a']++;
        for(auto& c:t)
            hist[c-'a']--;
        return all_of(hist.begin(),hist.end(),[](int k){return k==0;});
    }
};
