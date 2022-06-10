class Solution {
public:
    int lengthOfLongestSubstring1(string s) {
        vector<bool> hash(256,false);
        int result=0;
        int n = s.size();
        int l=0,r=0;
        while(r<n) {
            if(!hash[s[r]]) {
                hash[s[r++]] = true;
                result = max(result, r-l);
            }
            else {
                hash[s[l++]] = false;
            }
        }
        return result;
    }
    // keep track of previous occurence.
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
