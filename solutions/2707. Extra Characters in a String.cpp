const int LEN = 26;
struct TRIE{
    
    TRIE():next(LEN,nullptr),end{false}{
    }
    
    void search(string& s,int start,vector<int>& pos){
        if(end) pos.push_back(start);
        if(start >= s.size()) return;
        int idx = s[start]-'a';
        if(next[idx]){
            next[idx]->search(s,start+1,pos);
        }
    }
    void insert(string &s){
        TRIE* curr = this;
        for(auto& c: s){
            if(!curr->next[c-'a'])
                curr->next[c-'a'] = new TRIE();
            curr = curr->next[c-'a'];
        }
        curr->end = true;
    }
private:
    vector<TRIE*> next;
    bool end;
};
​
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        TRIE dict;
        int n = s.size();
        for(auto& str:dictionary)
            dict.insert(str);
        vector<int> dp(n,-1);
        function<int(int)> extras = [&](int idx){
            
            if(idx>= n) return 0;
            if(dp[idx] != -1)
                return dp[idx];
            
            vector<int> pos;
            dict.search(s,idx,pos);
            dp[idx] = numeric_limits<int>::max();
            for(auto& p:pos){
                dp[idx] = min(dp[idx],extras(p));
            }
            for(int p = idx+1;p<n;p++){
                dp[idx] = min(dp[idx],extras(p) + p-idx);
            }
            
            if(dp[idx] > n)
                dp[idx] = n-idx;
            return dp[idx];
        };
        return extras(0);
    }
};
