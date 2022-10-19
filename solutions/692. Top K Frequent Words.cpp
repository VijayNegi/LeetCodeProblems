class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        unordered_map<string,int> count;
        unordered_map<int,set<string>> fre2str;
        for(auto& s:words) {
            count[s]++;
            fre2str[count[s]].insert(s);
            if(count[s]!=1) {
                fre2str[count[s]-1].erase(s);
            }
        }
        for(int i=500;i>0;--i) {
            if(fre2str[i].size()==0)
                continue;
            result.insert(result.end(),fre2str[i].begin(),fre2str[i].end());
            if(result.size()>=k)
                break;
        }
        result.resize(k);
        return result;
    }
};
