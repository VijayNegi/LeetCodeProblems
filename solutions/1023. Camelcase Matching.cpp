class Solution {
public:
    bool camelMatch(string& s,string& p)
    {
        int ns = s.size();
        int np = p.size();
        int is=0,ip=0;
        while(is<ns && ip<np)
        {
            if(islower(s[is]) && (isupper(p[ip]) || s[is]!=p[ip]))
            {
                ++is;
                continue;
            }
            if(s[is]!=p[ip])
                return false;
            ++is,++ip;
        }
        while(is<ns)
        {
            if(isupper(s[is]))
                return false;
            ++is;
        }
        if(ip == np)
            return true;
        return false;
    }
    vector<bool> camelMatch1(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> result(n);
        for(int i=0;i<n;++i)
        {
            result[i] = camelMatch(queries[i],pattern);
        }
        return result;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (string &query : queries) res.push_back(isMatch(query, pattern));
        return res;
​
    }
​
    bool isMatch(string query, string pattern) {
        int i = 0;
        for (char & c : query)
            if (i < pattern.length() && c == pattern[i]) i++;
            else if (c < 'a') return false;
        return i == pattern.length();
    }
};
