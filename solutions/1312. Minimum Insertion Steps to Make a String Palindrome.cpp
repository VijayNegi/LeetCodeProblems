class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector(n,-1));
        function<int(int,int)> steps = [&](int l, int r){
            if(l>=r)
                return 0;
            if(dp[l][r]!= -1) return dp[l][r];
            
            int msteps =  INT_MAX;
            if(s[l]==s[r]){
                msteps = min(msteps, steps(l+1,r-1));
            }
            else {
                msteps = min(msteps, steps(l,r-1)+1);
                msteps = min(msteps, steps(l+1,r)+1);
            }
            return dp[l][r] = msteps;
        };
        return steps(0,n-1);
    }
};
