class Solution {
public:
    // self : dfs 428ms
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> oppo(n+1);
        vector<int> group(n+1,0);
        for(auto& d:dislikes){
            oppo[d[0]].push_back(d[1]);
            oppo[d[1]].push_back(d[0]);
        }
        for(int i=1;i<=n;++i){
            if(group[i]==0 && !dfs(i,1,group,oppo))
                return false;
        }
        return true;
    }
    bool dfs(int k,int g,vector<int>& group,vector<vector<int>>& oppo){
        if(group[k]!=0)
            return group[k]==g;
        group[k] = g;
        for(auto& dis:oppo[k])
            if(!dfs(dis,3-g,group,oppo))
                return false;
        return true;
    }
};
