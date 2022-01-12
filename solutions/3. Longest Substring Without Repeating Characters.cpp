class Solution {
public:
    //sliding window : 12 ms
    int lengthOfLongestSubstring1(string s) {
        int n = s.size();
        int l=0,r;
        int u = 0;
        vector<int> dp(256,0);
        for(r=0;r<n;++r)
        {
            char c = s[r];
            ++dp[c];
            if(dp[c]==1)
                ++u;
            
            if(r+1-l > u)
            {
                if(--dp[s[l++]] == 0)
                    --u;
            }
        }
        
        return r-l;
    }
    // keep track of previous occurence. : 8 ms
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
