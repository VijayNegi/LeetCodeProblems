class Solution {
public:
    // self : 335 ms
    int numMatchingSubseq1(string s, vector<string>& words) {
        int n = s.size();
        function<bool(const string&)> match = [&](const string& str) {
            int i=0,j=0;
            int sn = str.size();
            if(sn>n)
                return false;
            while(i<n && j<sn) {
                if(s[i++]==str[j])
                    ++j;
            }
            return j==sn;
        };
        int result=0;
        map<string,int> unique;
        for(auto& w:words)
            unique[w]++;
        for(auto& w:unique){
            if(match(w.first))
                result+=w.second;
        }
        return result;
    }
    //https://leetcode.com/problems/number-of-matching-subsequences/discuss/117634/Efficient-and-simple-go-through-words-in-parallel-with-explanation
    // 218 ms
    int numMatchingSubseq2(string S, vector<string>& words) {
        vector<pair<int, int>> waiting[128];
        for (int i = 0; i < words.size(); i++)
            waiting[words[i][0]].emplace_back(i, 1);
        for (char c : S) {
            auto advance = waiting[c];
            waiting[c].clear();
            for (auto it : advance)
                waiting[words[it.first][it.second++]].push_back(it);
        }
        return waiting[0].size();
    }
    // using char*
    // 231 ms
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<const char*> waiting[128];
        for (auto &w : words)
            waiting[w[0]].push_back(w.c_str());
        for (char c : S) {
            auto advance = waiting[c];
            waiting[c].clear();
            for (auto it : advance)
                waiting[*++it].push_back(it);
        }
        return waiting[0].size();
    }
};
