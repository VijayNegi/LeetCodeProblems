class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mAna;
        
        for(auto n: strs)
        {
            int a[26]={0};
            for(auto c:n)
                a[c -'a']++;
            string key;
            for(int i=0;i<26;++i)
                if(a[i]) key.append(a[i],'a'+i);
            
            mAna[key].push_back(n);
        }
        
        vector<vector<string>> result;
        for(auto vec:mAna)
        {
            result.push_back(vec.second);
        }
        return result;
    }
};
