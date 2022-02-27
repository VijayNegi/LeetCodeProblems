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
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = queries.size();
        vector<bool> result(n);
        for(int i=0;i<n;++i)
        {
            result[i] = camelMatch(queries[i],pattern);
        }
        return result;
    }
};
