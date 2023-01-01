class Solution {
public:
    bool wordPattern1(string pattern, string s) {
        unordered_set<string> seen;
        unordered_map<char,string> match;
        string token;
        stringstream ss(s);
        int i=0;
        while(getline(ss,token,' ')){
            if(i==pattern.size())
                return false;
            if(match.count(pattern[i])){
                if(match[pattern[i]] != token)
                    return false;
            }
            else if(seen.count(token))
                return false;
            match[pattern[i]] = token;
            seen.insert(token);
            ++i;
        }
        if(i!=pattern.size())
                return false;
        return true;
    }
    // just cleaner
    bool wordPattern(string pattern, string str) {
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || p2i[pattern[i]] != w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i + 1;
        }
        return i == n;
    }
};
