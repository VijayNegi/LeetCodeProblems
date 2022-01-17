class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = s.size();
        int pn = pattern.size();
        unordered_map<char,string> ptoword;
        unordered_map<string,char> wordtop;
        int space = 0;
        int pIdx = 0;
        for(int i=0;i<n;++i)
        {
            if(isspace(s[i]))
            {
                if(pIdx==pn)
                    return false;
                string sub = s.substr(space,i-space);
                char c = pattern[pIdx];
                if(ptoword.count(c))
                {
                    if(ptoword[c] != sub)
                        return false;
                }
                else if (wordtop.count(sub))
                {
                     if(wordtop[sub] != c)
                        return false;
                }
                else
                {
                    ptoword[c] = sub;
                    wordtop[sub] = c;
                }
                
                space = i+1;
                ++pIdx;
            }
        }
        // check last word
        string sub = s.substr(space,n-space);
        char c = pattern[pIdx];
        if(ptoword.count(c))
        {
            if(ptoword[c] != sub)
                return false;
        }
        else if (wordtop.count(sub))
        {
             if(wordtop[sub] != c)
                return false;
        }
        else
        {
            ptoword[c] = sub;
            wordtop[sub] = c;
        }
​
        ++pIdx;
        
        if(pIdx != pn)
            return false;
        
        return true;
        
    }
};
