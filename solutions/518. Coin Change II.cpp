class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0] = 1;
        // Below loops will count combination with places which dont matter
        // for(int i=0;i<=amount;++i){
        //     for(auto& c:coins){
        //         if(i+c<=amount)
        //             dp[i+c] += dp[i];
        //     }
        // }
        for(auto& c:coins){
            for(int i=0;i<=amount;++i){
                if(i+c<=amount)
                    dp[i+c] += dp[i];
            }
        }
        return dp[amount];
    }
};
