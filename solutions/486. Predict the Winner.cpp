class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector(n,-1));
        function<int(int,int)> canWin = [&](int l,int r){
            if(l==r){
                return nums[l];
            }
            if(dp[l][r] != -1) return dp[l][r];
            int diff1 = nums[r] - canWin(l,r-1);
            int diff2 = nums[l] - canWin(l+1,r);
            return dp[l][r] = max(diff1,diff2);;
        };
        return canWin(0,n-1)>=0;
    }
};
