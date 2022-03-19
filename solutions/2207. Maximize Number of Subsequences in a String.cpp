class Solution {
public:
    // contest 93ms
    long long maximumSubsequenceCount1(string text, string pattern) {
        int n = text.size();
        vector<int> p2(n+1,0);
        int count=0;
        for(int i=n-1;i>=0;--i)
        {
            if(text[i]==pattern[1])
                ++count;
            p2[i] = count;
        }
        long long result=0;
        count=0;
        for(int i=0;i<n;++i)
        {
            if(text[i]==pattern[0])
            {
                result += p2[i+1];
                ++count;
            }
        }
        return result+max(p2[0],count);   
    }
    
    // clean 55ms
    long long maximumSubsequenceCount(string text, string pattern) {
        long long res = 0, cnt1 = 0, cnt2 = 0;
        for (char& c: text) {   
            if (c == pattern[1])
                res += cnt1, cnt2++;
            if (c == pattern[0])
                cnt1++;
        }
        return res + max(cnt1, cnt2);
    }
};
