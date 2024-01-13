class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26,0);
        for(auto& c:s) freq[c-'a']++;
        for(auto& c:t) freq[c-'a']--;
        int result=0;
        for(auto& n:freq) if(n>0) result+=n;
        return result;
    }
};
