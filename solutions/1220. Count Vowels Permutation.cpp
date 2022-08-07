const int mod = 1e9+7;
class Solution {
public:
    // 327 ms
    int countVowelPermutation1(int n) {
        map<char,vector<char>> pre;
        pre['a'] = {'e','i','u'};
        pre['e'] = {'a','i'};
        pre['i'] = {'e','o'};
        pre['o'] = {'i'};
        pre['u'] = {'i','o'};
​
        vector<int> dp(256,0);
        for(auto& c: pre) {
            dp[c.first] = 1;
        }
        
        for(int i=1;i<n;++i) {
            vector<int> temp(256,0);
            for(auto& c: pre) {
                int ch = c.first;
                for(auto& k: c.second) {
                    temp[k] =  ((long)temp[k] + dp[ch])%mod;
                }
            }
            swap(dp,temp);
        }
        long result = 0;
        for(auto& c: pre) {
            result += dp[c.first];
            result %= mod;
        }
        return result;
    }
    // 111 ms
    int countVowelPermutation(int n) {
        const int mod = 1e9+7;
        vector<int> curr(5,1) ;
        
        for(int i=2;i<=n;++i)
        {
            vector<int> next(5,0);
            next[0] = ((curr[1] + curr[2])%mod + curr[4])%mod;
            next[1] = (curr[0] + curr[2])%mod;
            next[2] = (curr[1] + curr[3])%mod;
            next[3] = (curr[2])%mod;
            next[4] = (curr[2] + curr[3])%mod;
            curr = next;
        }
        int sum=0;
        for(int k=0;k<5;++k)
            sum  = (sum + curr[k])% mod;
        
        return sum;
    }
};
​
