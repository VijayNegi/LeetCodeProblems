class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> dict(26,0);
        int i=0;
        for(auto& c: order)
            dict[c-'a'] = i++;
        int n = words.size();
        for(i=1;i<n;++i){
            int l = min(words[i].size(),words[i-1].size());
            int j=0;
            for(;j<l;++j){
                if(dict[words[i-1][j]-'a']>dict[words[i][j]-'a']) return false;
                else if(dict[words[i-1][j]-'a']<dict[words[i][j]-'a'])  break;
            }
            if(j==l && words[i-1].size()>l)
                return false;
        }
        return true;
    }
};
