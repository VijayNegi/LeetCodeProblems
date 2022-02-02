class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> phist(26,0);
        vector<int> thist(26,0);
        for(auto c:p)
            ++phist[c-'a'];
​
        int np = p.size();
        int ns = s.size();
        vector<int> res;
        for(int i=0;i<ns;++i)
        {
            ++thist[s[i]-'a'];
            if(i>=np-1)
            {
                if(i>=np)
                    --thist[s[i-np]-'a'];
                if(phist==thist)
                    res.push_back(i-np+1);
            }
        }
        return res;
    }
};
