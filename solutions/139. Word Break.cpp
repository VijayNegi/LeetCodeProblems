            if(!node->next[c])
                break;
            node = node->next[c];
            ++idx;
        }
        return res;
    }
};
class Solution {
public:
    // TLE , only AC if you keep check if you have already tried that idx.
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> wmap(26);
        for(auto& w:wordDict)
        {
            wmap[w[0]-'a'].push_back(w);
        }
        int n = s.size();
        vector<bool> check(n,false);
        function<bool(string,int)> recurse =  [&](string s,int idx)
        {
            if(check[idx])
                return false;
            check[idx] = true;
            if(s.size() == idx)
                return true;
            for(auto& w:wmap[s[idx]-'a'])
            {
                int t=0;
                int i=idx;
                while(t<w.size() && i<s.size())
                {
                    if(w[t] != s[i])
                        break;
                    ++t;
                    ++i;
                }
                if(t==w.size())
                    if(recurse(s,idx+t))
                        return true;
            }
            return false;
        };
        return recurse(s,0);
    }
    // TRIE based solution, only AC if you keep check if you have already tried that idx.
    bool wordBreak1(string s, vector<string>& wordDict) {
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
