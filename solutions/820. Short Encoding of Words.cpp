class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(),words.end());
        for(auto w:words) {
            if(s.count(w)) {
                int n = w.size();
                for(int i=0;i<n-1;++i) {
                    string sub = w.substr(n-i-1);
                    if(s.count(sub))
                        s.erase(sub);
                }
            }
        }
        int result = 0;
        for(auto str:s) {
            result += str.size() +1;
        }
        return result;
    }
};
