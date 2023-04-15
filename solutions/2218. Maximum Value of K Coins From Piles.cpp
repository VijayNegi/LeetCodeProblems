class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> mem(n+1,vector(k+1,-1));
        for(auto& p: piles){
            for(int i=1;i<p.size();++i)
                p[i]+= p[i-1];
        }
        function<int(int,int)> dfs = [&](int p,int r){
            if(p>=n || r<=0 ) return 0;
            if(mem[p][r]!= -1)return mem[p][r];
            int n1 = piles[p].size();
            int res = dfs(p+1,r);
            for(int i=0;i<n1 && i<r;++i){
                res = max(res,piles[p][i]+dfs(p+1,r-i-1));
            }
            return mem[p][r] = res;
        };
        return dfs(0,k);
    }
};
