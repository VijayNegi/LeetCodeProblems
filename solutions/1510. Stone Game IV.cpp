class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,false);
        
        // Alice starts first
        dp[1] = true;
        
        for(int i=2;i<=n;++i)
        {
            for(int sq=1;sq*sq<=i; ++sq)
            {
                if(dp[i-sq*sq] == false)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
