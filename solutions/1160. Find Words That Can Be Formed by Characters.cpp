class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        function<vector<int>(string&)> getFreq = [](string& s){
            vector<int> f(26,0);
            for(auto& c:s)
                f[c-'a']++;
            return f;
        };
        function<bool(vector<int>,vector<int>&)> good = [](vector<int> v1,vector<int>& v2){
            for(int i=0;i<26;++i)
                if(v1[i]>v2[i]) return false;
            return true;
        };
        int result=0;
        auto freq = getFreq(chars);
        for(auto& s: words)
            if(good(getFreq(s), freq))
                result += s.size();
        return result;
    }
    
};
