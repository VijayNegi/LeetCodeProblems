const int mod = 1e9+7;
class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> edges{
            {4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}
        };
        vector<int> dp(10,1);
        vector<int> curr(10,0);
        for(int i=1;i<n;++i){
            for(int j=0;j<10;++j){
                curr[j]=0;
                for(auto& e:edges[j]){
                    curr[j] = (curr[j] + dp[e])%mod;
                }
            }
            swap(curr,dp);
        }
        int result=0;
        for(auto& num:dp){
            result  = (result+num)%mod;
        }
        return result;
    }
};
