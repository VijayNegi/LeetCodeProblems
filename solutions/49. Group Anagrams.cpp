class Solution {
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
public:
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
};
