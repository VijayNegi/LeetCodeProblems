            node = node->next[c];
            ++idx;
        }
        return res;
    }
};
class Solution {
public:
    bool wordBreak1(string s, vector<string>& wordDict) {
        vector<vector<int>> char2Dict(26);
        int n = s.size();
        for(int i=0;i<wordDict.size();++i){
            char2Dict[wordDict[i][0]-'a'].push_back(i);
        }
        vector<bool> dp(n,false);
        function<bool(int)> recurse = [&](int pos){
            if(pos==n) return true;
            if(dp[pos]==true) return false;
            dp[pos]=true;
            for(auto& i: char2Dict[s[pos]-'a']){
                
                string& w = wordDict[i];
                if(w.size()+pos > n)
                    continue;
                int k=0,p1 = pos;
                while(k<w.size() && p1<n){
                    if(w[k]!=s[p1])
                        break;
                    ++k,++p1;
                }
                if(k==w.size() && recurse(p1))
                    return true;  
            }
            return false;
        };
        return recurse(0);
    }
   // old solution : TRIE
    bool wordBreak(string s, vector<string>& wordDict) {
        trie dict;
        for(auto& w:wordDict)
            dict.insert(w,0);
        int n = s.size();
        list<int> q{0};
        vector<bool> check(n,false);
        while(!q.empty())
        {
            int i = q.front();
            q.pop_front();
            if(check[i])
                continue;
            check[i] = true;
            auto l = dict.search(s,i);
            if(l.front() == n)
                return true;
            q.insert(q.begin(),l.begin(),l.end());
        }
        
        return false;
    }
};
​
​
