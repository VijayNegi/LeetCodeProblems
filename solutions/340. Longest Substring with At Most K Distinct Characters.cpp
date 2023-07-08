class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k==0) return 0;
        vector<int> seen(256,0);
        int distinct = 0;
        int start=0;
        int n = s.size();
        int result=0;
        for(int i=0;i<n;++i){
            ++seen[s[i]];
            if(seen[s[i]]==1)
                ++distinct;
            while(distinct>k){
                --seen[s[start]];
                if(seen[s[start]]==0)
                    --distinct;
                ++start;
            }
            result = max(result, i-start+1);
        }
        return result;
    }
};
