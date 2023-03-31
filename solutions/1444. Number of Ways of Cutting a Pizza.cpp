const int mod = 1e9+7;
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size();
        int cols = pizza[0].size();
        vector<vector<int>> acount(rows,vector(cols,0));
        int result=0;
        for(int r=rows-1;r>=0;--r)
            for(int c = cols-1;c>=0;--c){
                acount[r][c] = pizza[r][c]=='A';
                if(r!=rows-1) acount[r][c] += acount[r+1][c];
                if(c!=cols-1) acount[r][c] += acount[r][c+1];
                if(c!=cols-1 && r!=rows-1) acount[r][c] -= acount[r+1][c+1];
            }
        if(acount[0][0]==0) return 0;
        vector<vector<vector<int>>> dp(rows,vector(cols,vector(k+1,-1)));
        function<int(int,int,int)> dfs = [&](int r,int c,int t){
            
            if(r>=rows || c>=cols) return 0;
            if(t==1) return 1;
            if(dp[r][c][t]!=-1) return dp[r][c][t];
            int temp=0;
            for(int r1 = r+1;r1<rows;++r1){
                if(acount[r][c]==acount[r1][c] || acount[r1][c]==0) continue;
                temp += dfs(r1,c,t-1);
                temp%=mod;
            }
            for(int c1 = c+1;c1<cols;++c1){
                if(acount[r][c]==acount[r][c1] || acount[r][c1]==0) continue;
                temp += dfs(r,c1,t-1);
                temp%=mod;
            }
            //cout<<r<<" "<<c<<" "<<t<<"="<<temp<<endl;
            return dp[r][c][t] = temp;
        };
        
        return dfs(0,0,k);
    }
};
