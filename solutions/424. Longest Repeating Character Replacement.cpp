class Solution {
public:
    // O(n^2)
    int characterReplacement1(string s, int k) {
        int n = s.size();
        int res = 0;
        //vector<bool> start[false]
        for(int i=0;i<n-k;++i)
        {
            if(i>0)
            {
                while(s[i]==s[i-1]) // skip same chars as we cannot get best res from them
                    ++i;
            }
            int j = i;
            int k1 = k;
            for(j=i+1;j<n && k1>=0;++j)
            {
                if(s[i]==s[j])
                    continue;
                else
                    --k1;
            }
            res = max(res,j-i+k1);
        }
        return min(res,n);
    }
    // sliding window
    int characterReplacement2(string s, int k) {
        int n = s.size();
        int freq[26] = {0};
        int maxfreq,start,end,result;
        maxfreq = start = end = result = 0; 
        for(end = 0;end < n; ++end)
        {
            int lastChar = s[end]-'A';
            freq[lastChar]++;
            maxfreq = max(maxfreq, freq[lastChar]);
            if( (end - start) -  maxfreq< k)
                result = end - start+1; // we dont need to use max as start - end will never shrink ones expended i.e. window can become invalid inbetween
            else
            {
                --freq[s[start] - 'A'];
                ++start;
            }
        }
        return result;
    }
    
    // just little clearner then previous
    int characterReplacement3(string s, int k) {
        int maxf = 0, i = 0, n = s.length();
        vector<int> count(26);
        for (int j = 0; j < n; ++j) {
            maxf = max(maxf, ++count[s[j] - 'A']);
            if (j - i + 1 > maxf + k)
                --count[s[i++] - 'A'];
        }
        return n - i;
    }
    
    // sliding window , same as above but dont need to keep tack of start and end
    int characterReplacement(string s, int k) {
        int res = 0, maxf = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < s.length(); ++i) {
            maxf = max(maxf, ++count[s[i]]);
            if (res - maxf < k)
                res++;
            else
                count[s[i - res]]--;
        }
        return res;
    }
    
    
};
