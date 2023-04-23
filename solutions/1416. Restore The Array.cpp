const int mod = 1e9+7;
class Solution {
public:
    // Top down : 122 ms
    int numberOfArrays1(string s, int k) {
        int n = s.size();
        vector<int> dp(n,-1);
        function<int(int)> ways = [&](int pos){
            if(pos==n) return 1;
            if(dp[pos] != -1) return dp[pos];
            if(s[pos] == '0') return dp[pos] = 0;
            long num = 0;
            int p = pos;
            int count = 0;
            while(p < n){
                num = num*10 + s[p++]-'0';
                if(num >k) break;
                count += ways(p);
                count %=mod;
            }
            return dp[pos] = count;
        };
        return ways(0);
    }
    // Bottom up: 64 ms
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=0;i<n;++i){
            if(s[i]=='0') continue;
            long num = 0;
            for(int j=i;j<n;++j){
                num = num*10 + s[j]-'0';
                if(num >k) break;
                dp[j+1] = (dp[j+1] + dp[i])%mod;
            }
        }
        return dp[n];
    }
};
