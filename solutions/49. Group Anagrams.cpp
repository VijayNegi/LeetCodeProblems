class Solution {
public:
    // new : 31 ms
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        vector<vector<string>> result;
        vector<pair<string,int>> sorted;
        for(int i=0;i<strs.size();++i){
            string s = strs[i];
            sort(s.begin(),s.end());
            sorted.push_back({s,i});
        }
        sort(sorted.begin(),sorted.end());
        string pre="-";
        for(auto& s:sorted){
            if(s.first != pre)
                result.push_back({strs[s.second]});
            else
                result.back().push_back(strs[s.second]);
            pre = s.first;
        }
        return result;    
    }
    
    // old solution
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mAna;
        
        for(auto n: strs)
        {
            mAna[strSort(n)].push_back(n);
        }
        
        vector<vector<string>> result;
        for(auto vec:mAna)
        {
            result.push_back(vec.second);
        }
        return result;
    }
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t.append(counter[c], c + 'a');
        }
        return t;
    }
};
