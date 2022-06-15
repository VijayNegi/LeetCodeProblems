class Solution {
public:
    // 252 ms
    int longestStrChain1(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[](string& l,string& r){return l.size()>r.size();});
        int result=1;
        unordered_map<string,int> s;
        for(auto& w:words)
            s[w]=1;
        for(auto& w:words) {
            int k = w.size();
            for(int i=0;i<w.size();++i) {
                string temp = w.substr(0,i) + w.substr(i+1, k-i-1);
                if(s[temp]) {
                    s[temp] = max(s[temp],s[w]+1);
                    result = max(result,s[temp]);
                }
            }
        }
        return result;
    }
    // substring matching optimized: 185 ms
    int longestStrChain2(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[](string& l,string& r){return l.size()>r.size();});
        int result=1;
        unordered_map<string,int> s;
        for(auto& w:words)
            s[w]=1;
        for(auto& w:words) {
            int k = w.size();
            string w1 = w;
            for(int i=0;i<k;++i) {
                swap(w1[0],w1[i]);      // note this will generate all substrs with removing one char
                string temp = w1.substr(1); // remove first char
                if(s[temp]) {
                    s[temp] = max(s[temp],s[w]+1);
                    result = max(result,s[temp]);
                }
            }
        }
        return result;
    }
    //https://leetcode.com/problems/longest-string-chain/discuss/2153007/C%2B%2BPython-Simple-Solution-w-Explanation-or-DP
    // 150ms
    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> dp;
        int res = 1;
        sort(words.begin(), words.end(), [](const string &l, const string &r) { return l.size() < r.size(); });
        for (string word : words) {
            dp[word] = 1;
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(prev) != dp.end()) {
                    dp[word] = dp[prev] + 1;
                    res = max(res, dp[word]);
                }
            }
        }
        return res;
    }
    
};
