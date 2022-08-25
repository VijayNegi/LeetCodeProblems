class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hist(26,0),hist_ran(26,0);
        for(auto& c:magazine) 
            hist[c-'a']++;
        for(auto& c:ransomNote) 
            hist_ran[c-'a']++;
        for(int i=0;i<26;++i)
            if(hist_ran[i]>hist[i])
                return false;
        return true;
    }
};
