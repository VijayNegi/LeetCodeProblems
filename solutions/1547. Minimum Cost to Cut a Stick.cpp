class Solution {
public:
    // pick closer to middle, wrong approach
    int minCost1(int n, vector<int>& cuts) {
        sort(begin(cuts),end(cuts));
        function<int(int,int,vector<int>&)> dfs = [&](int l,int r,vector<int>& c){
            //cout<<l<<" "<<r<<" c="<< c.size()<<endl;
            int m = l + (r-l)/2;
            if(c.size()==1) return r-l;
            if(c.size()==0) return 0;
            auto it = lower_bound(begin(c),end(c),m);
            int pos=-1;
            if(it==c.end()){
                auto itb = prev(it);
                vector<int> first(c.begin(),itb);
                vector<int> second(next(itb),c.end());
                return  r-l + dfs(l,*itb,first) + dfs(*itb,r,second);
            }
            else if(it == c.begin()){
                vector<int> first(c.begin(),it);
                vector<int> second(next(it),c.end());
                return  r-l +dfs(l,*it,first) + dfs(*it,r,second);
            }
            else{
                auto itb = prev(it);
                if(m-*itb < *it-m)
                    it = itb;
                vector<int> first(c.begin(),it);
                vector<int> second(next(it),c.end());
                return  r-l +dfs(l,*it,first) + dfs(*it,r,second);
            }
            return 0;
        };
        return dfs(0,n,cuts);
    }
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/discuss/780880/DP-with-picture-(Burst-Balloons)
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts),end(cuts));
        int m = cuts.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        function<int(int,int)> dfs = [&](int l,int r){
            if(dp[l][r] != -1) return dp[l][r];
            if(r-l==1) return 0;
            dp[l][r]=INT_MAX;
            for(int i=l+1;i<r;++i){
               dp[l][r] = min(dp[l][r], cuts[r]-cuts[l]+ dfs(l,i)+dfs(i,r));
            }
            //if(dp[l][r] == INT_MAX)
            //    dp[l][r]=0;
            return dp[l][r];
        };
        return dfs(0,m-1);
    }
};
