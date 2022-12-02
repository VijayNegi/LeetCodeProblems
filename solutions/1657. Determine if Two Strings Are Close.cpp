class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;
        int hist1[26]= {0},hist2[26]={0};
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
        vector<int> v1,v2;
        for(auto& h:hist1)
            if(h) v1.push_back(h);
        for(auto& h:hist2)
            if(h) v2.push_back(h);
        
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1 == v2)
            return true;
        return false;
        
    }
};
