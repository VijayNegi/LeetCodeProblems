struct DSU{
    int n;
    vector<int> parent;
    vector<int> rank;
    
    DSU(int _n):n(_n),parent(_n+1),rank(_n+1,INT_MAX){
        iota(parent.begin(),parent.end(),0);
    }
    int find(int id){
        if(parent[id]==id) return id;
        return parent[id] = find(parent[id]);
    }
    void merge(int id1,int id2,int newRank){
        int pid1 = find(id1);
        int pid2 = find(id2);
        if(pid1 == pid2) {
            rank[pid1] = min(rank[pid1],newRank);
            return;
        }
        parent[pid2] = pid1;
        rank[pid1] = min(rank[pid1],min(rank[pid2],newRank));
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DSU dsu(n);
        for(auto& v:roads){
            dsu.merge(v[0],v[1],v[2]);
        }
        return dsu.rank[dsu.find(1)];
    }
};
