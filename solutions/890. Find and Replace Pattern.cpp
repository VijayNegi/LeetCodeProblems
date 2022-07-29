class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = pattern.size();
        function<bool(string&,string&)> comp = [&](string& str1, string& str2) {
            vector<int> h1(26,-1),h2(26,-1);
            for(int i=0;i<n;++i) {
                int i1 = str1[i]-'a';
                int i2 = str2[i]-'a';
                if(h1[i1]!=-1 && h1[i1] != i2)
                    return false;
                h1[i1] = i2;
                if(h2[i2]!=-1 && h2[i2] != i1)
                    return false;
                h2[i2] = i1;
            }
            return true;
        };
        vector<string> result;
        for(auto& s:words) 
            if(comp(s,pattern))
                result.push_back(s);
        return result;
    }
};
