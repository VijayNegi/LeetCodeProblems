// understanding - https://leetcode.com/problems/remove-boxes/discuss/101310/Java-top-down-and-bottom-up-DP-solutions
// cases - https://leetcode.com/problems/remove-boxes/discuss/1402561/C%2B%2BJavaPython-Top-down-DP-Clear-explanation-with-Picture-Clean-and-Concise
class Solution {
    int removeBoxesSub(vector<int>& boxes,int i,int j,int k,vector<vector<vector<int>>>& dp)
    {
        if(j<i)
            return 0;
        if(dp[i][j][k]>0) return dp[i][j][k];
        
        int i0 = i,k0=k;
        for (; i + 1 <= j && boxes[i + 1] == boxes[i]; i++, k++);
        
        int result = (k+1) * (k+1) + removeBoxesSub(boxes,i+1,j,0,dp);
        for(int m= i+1;m<=j;++m)
        {
            if(boxes[i]==boxes[m])
                result = max(result, removeBoxesSub(boxes,i+1,m-1,0,dp) + removeBoxesSub(boxes,m,j,k+1,dp));
        }
        
        dp[i0][j][k0] = result;
        return result;
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n+1,vector(n+1,vector<int>(n+1,0)));
        //vector<vector<vector<int>>> dp(n,vector<int>(n,vector<int>(n,0)));
        return removeBoxesSub(boxes,0,n-1,0,dp);
    }
};
