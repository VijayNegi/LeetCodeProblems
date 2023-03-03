                ++k;
            if(k==n)
            {
                return i-n+1;
            }
        }
        return -1;
    }
    
    // start with -1
    vector<int> prefix_function2(string s) {
        int n = s.size();
        vector<int> pi(n + 1, 0);
        pi[0] = -1;
        int k = -1;
              
        for (int i = 0; i < n; i++) {
            while(k >= 0 && s[k] != s[i]) 
                k = pi[k];
            pi[i+1] = ++k;
        }
        
        return pi;
    }
    
    int strStr(string haystack, string needle) {
        int h = haystack.size(), n = needle.size();
        if(n==0)
            return 0;
        if(n>h)
            return -1;
        vector<int> pi = prefix_function2(needle);
        int k=0;
        for(int i=0;i<h;++i)
        {
            while(k>=0 && needle[k] != haystack[i])
                k = pi[k];
            ++k;
            if(k==n)
            {
                return i-n+1;
            }
        }
        return -1;
    }
    
};
