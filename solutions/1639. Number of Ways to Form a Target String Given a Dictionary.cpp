const int mod = 1e9+7;
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int t = target.size();
        vector<map<char,int>> freq(n);
        for(auto& w:words){
            for(int i=0;i<w.size();++i)
                freq[i][w[i]]++;
        }
        long result=0;
        vector<vector<long>> dp(n,vector<long>(t,-1));
        function<long(int,int)> dfs = [&](int id,int p) -> long{
            if(p==t) return 1;
            if(id==n) return 0;
            if(dp[id][p] != -1) return dp[id][p];
            long res=0;
            long c = freq[id][target[p]];
            if(c){
                res = dfs(id+1,p+1);
                res  = (res*c)%mod;
            }
            res += dfs(id+1,p);
            res %= mod;
            return dp[id][p] = res;
        };
        return dfs(0,0);
    }
};
