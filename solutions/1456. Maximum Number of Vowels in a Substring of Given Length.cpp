class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> ss{'a','e','i','o','u'};
        int v=0,maxv=0;
        for(int i=0;i<s.size();++i){
            if(i>=k)
                if(ss.count(s[i-k])) --v;
            if(ss.count(s[i])) ++v;
            maxv = max(v,maxv);
        }
        return maxv;
    }
};
