const int mod = 1e9+7;
class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<int> dp(n,-1);
        function<int(int)> dfs = [&](int k){
            if(k>=n) return 0;
            long long count=0;
            if(dp[k]!=-1) return dp[k];
            int org = k;
            dp[org]=0;
            long long plant=0;
            while(k<n){
                if(corridor[k]=='S') ++count;
                else if(count==2 && corridor[k]=='P') ++plant;
                if(count == 3) dp[org] = (dp[org] + (dfs(k) * (plant+1) ))%mod;
                if(count>=3) break;
                ++k;
            }
            if(k==n && count==2)
                dp[org]=1;
            return dp[org];
        };
        
        return dfs(0);
        
    }
};
