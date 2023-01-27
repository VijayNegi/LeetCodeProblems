class Solution {
public:
    // self : 897ms
    vector<string> findAllConcatenatedWordsInADict1(vector<string>& words) {
        sort(words.begin(),words.end(),[](string& l,string& r){return l.size()<r.size();});
        unordered_map<char,vector<string>> dict;
        vector<string> result;
        
        function<bool(string&,int)> dfs = [&](string& str,int idx){
            if(idx == str.size()){
                result.push_back(str);
                return true;
            }
            for(auto& ss: dict[str[idx]]){
                if(ss.size()+idx <= str.size() && ss == str.substr(idx,ss.size()))
                    if(dfs(str,idx+ss.size())) return true;
            }
            return false;
        };
        
        for(auto& w: words){
            dfs(w,0);
            dict[w[0]].push_back(w);
        }
        return result;
    }
    // 281ms
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> res;
        for (auto w : words) {
            int n = w.size();
            vector<int> dp(n+1);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (dp[i] == 0) continue;
                for (int j = i+1; j <= n; j++) {
                    if (j - i < n && s.count(w.substr(i, j-i))) dp[j] = 1;
                }
                if (dp[n]) { res.push_back(w); break; }
            }
        }
        return res;
    }
};
