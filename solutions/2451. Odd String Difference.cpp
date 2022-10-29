class Solution {
public:
    string oddString(vector<string>& words) {
        for(int i=1;i<words[0].size();++i){
            unordered_map<int,int> count;
            unordered_map<int,int> id;
            for(int j=0;j<words.size();++j){
                count[words[j][i]-words[j][i-1]]++;
                id[words[j][i]-words[j][i-1]]=j;
            }
            for(auto& c:count){
                if(c.second == 1)
                    return words[id[c.first]];
            }
        }
        return "";
    }
};
