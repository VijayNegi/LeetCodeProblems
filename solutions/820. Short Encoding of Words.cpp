class Solution {
public:
    // self : 93 ms
    int minimumLengthEncoding1(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        for (string w : s)
            for (int i = 1; i < w.size(); ++i)
                s.erase(w.substr(i));
        int res = 0;
        for (string w : s) res += w.size() + 1;
        return res;
    }
    // use string view : 62ms
    int minimumLengthEncoding2(vector<string>& words) {
        unordered_set<string_view> S(words.begin(), words.end());
        for (auto& w : words) {
            string_view sv(w);
            for (int i = 1; i < w.size(); i++) S.erase(sv.substr(i));
        }
        return accumulate(S.begin(), S.end(), 0, [](int total, const string_view& w){ return total + w.size() + 1; });
    }
    // https://leetcode.com/problems/short-encoding-of-words/discuss/125822/C%2B%2B-4-lines-reverse-and-sort
    // sort reversed strings : 56 ms
    int minimumLengthEncoding(vector<string>& ws, int res = 0) {
        for (auto i = 0; i < ws.size(); ++i) reverse(ws[i].begin(), ws[i].end());
        sort(ws.begin(), ws.end());
        for (auto i = 0; i < ws.size() - 1; ++i) res += ws[i] == ws[i + 1].substr(0, ws[i].size()) ? 0 : ws[i].size() + 1;
        return res + ws[ws.size() - 1].size() + 1;
    }
};
​
