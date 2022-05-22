class Solution {
public:
    // self
    int countSubstrings1(string s) {
        int n =s.size();
        int result=0;
        for(int i=0;i<n;++i) {
            int l,r;
            l=r=i;
            while(l>=0 && r<n && s[l--]==s[r++]) {
                ++result;
            }
        }
        for(int i=0;i<n-1;++i) {
            int l,r;
            l=i;
            r=l+1;
            while(l>=0 && r<n && s[l--]==s[r++]) {
                ++result;
            }
        }
        return result;
    }
    //cleaner
    int countSubstrings2(string s) {
        int counter = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                counter++;
            }
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                counter++;
            }
        }
        return counter;
    }
    
    // with manacher algorithm : 7ms
    int countSubstrings(string s) {
        string t;
        for(auto c: s) {
            t += string("#") + c;
        }
        auto res = manacher_odd(t + "#");
        int result = 0;
        for(auto p:res)
            result += p/2; //this is need because of current implimentation
        return result;
    }
    
    vector<int> manacher_odd(string s) {
        int n = s.size();
        string str = "^"+s+"$";
        int l=1,r=1;
        vector<int> p(n+2);
        for(int i=1;i<=n;++i) {
            p[i] = max(0, min(r-i,p[l+(r-i)]));
            while(str[i-p[i]] == str[i+p[i]])
                ++p[i];
            
            if(i+p[i]>r) {
                l = i-p[i];
                r = i+p[i];
            }
        }
        return vector<int>(begin(p) + 1, end(p) - 1);
    }
    
};
