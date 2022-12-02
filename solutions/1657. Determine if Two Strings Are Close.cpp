class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        vector<int> hist1(26,0),hist2(26,0);
        for(auto& c:word1)
            hist1[c-'a']++;
        for(auto& c:word2)
            hist2[c-'a']++;
        bool flg = true;
        for(int i=0;i<26;++i){
            if(hist1[i] != hist2[i])
                flg = false;
            if((hist1[i] && !hist2[i]) || (!hist1[i] && hist2[i])) // we can swap but cannot get new charactor
                return false;
        }
        if(flg)
            return true;
        
        sort(hist1.begin(),hist1.end());
        sort(hist2.begin(),hist2.end());
        if(hist1 == hist2)
            return true;
        return false;
        
    }
};
