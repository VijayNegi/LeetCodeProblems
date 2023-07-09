class Solution {
public:
    // self, n2, TLEhttps://github.com/VijayNegi/LeetCodeProblems/blob/main/solutions/2272.%20Substring%20With%20Largest%20Variance.cpp
    int largestVariance1(string s) {
        int result=0;
        int n = s.size();
        unordered_map<char,int> lastIdx;
        for(int i=0;i<n;++i)
            lastIdx[s[i]] = i;
        
        for(int i=0;i<n;++i){
            map<int,int> count2char;
            unordered_map<char,int> char2count;
            int last = lastIdx[s[i]];
            for(int j=i;j<=last;++j){
                int c = char2count[s[j]];
                ++char2count[s[j]];
                ++count2char[c+1];
                if(c){
                    --count2char[c];
                    if(!count2char[c])
                        count2char.erase(c);
                }
                result = max(result,count2char.rbegin()->first - count2char.begin()->first);
                if(char2count[s[j]] == j-i+1 && (i!=0 || j!=n-1))
                    result = max(result,char2count[s[j]] -1);
            }
        }
        return result;
    }
    // https://leetcode.com/problems/substring-with-largest-variance/discuss/2039178/Weird-Kadane
    int largestVariance2(string s) {
        int res = 0;
        unordered_set<char> unique(begin(s), end(s));
        for (char a : unique)
            for (char b : unique) {
                int var = 0, has_b = 0, first_b = 0;
                for (auto ch : s) {
                    var += ch == a;
                    if (ch == b) {
                        has_b = true;
                        if (first_b && var >= 0)
                            first_b = false;
                        else if (--var < 0) {
                            first_b = true;
                            var = -1;
                        }
                    }
                    res = max(res, has_b ? var : 0);
                }
            }
        return res;
    }
    // https://leetcode.com/problems/substring-with-largest-variance/discuss/2039178/Weird-Kadane/1395350
    int largestVariance(string s) {
        int ans = 0; 
        for (auto& x : "abcdefghijklmnopqrstuvwxyz") 
            for (auto& y : "abcdefghijklmnopqrstuvwxyz") 
                if (x != y) {
                    int prefix = 0, buff = 0, m = 10000; 
                    for (auto& ch : s) {
                        if (ch == x) ++prefix; 
                        else if (ch == y) {
                            m = min(m, buff);
                            buff = --prefix; 
                        }
                        ans = max(ans, prefix - m); 
                    }
                }
        return ans; 
    }

};
