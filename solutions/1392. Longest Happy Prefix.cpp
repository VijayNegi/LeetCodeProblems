class Solution {
public:
    vector<int> prefix(string s)
    {
        int n = s.size();
        int k=0;
        vector<int> pi(n,0);
        for(int i=1;i<n;++i)
        {
            while(k>0 && s[k]!=s[i])
                k = pi[k-1];
            if(s[k]==s[i])
                ++k;
            pi[i] = k;
        }
        return pi;
    }
    // KMP 46 ms
    string longestPrefix1(string s) {
        auto pre = prefix(s);
        return s.substr(0, pre.back());
    }
    // rolling hash based solution 28 ms
    string longestPrefix(string &s) {
        long h1 = 0, h2 = 0, mul = 1, len = 0, mod = 1000000007;
        for (int i = 0, j = s.length() - 1; j > 0; ++i, --j) {
            int first = s[i] - 'a', last = s[j] - 'a';
            h1 = (h1 * 26 + first) % mod;
            h2 = (h2 + mul * last) % mod;
            mul = mul * 26 % mod;
            if (h1 == h2)
                len = i + 1;
        }
        return s.substr(0, len);
    }
};
