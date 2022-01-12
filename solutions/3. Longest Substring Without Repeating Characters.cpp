class Solution {
public:
    //sliding window : 12 ms
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0,r=n-1;
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
};
