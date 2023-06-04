struct DSU {
    vector<int> parent;
    int n;
    DSU(int _n):parent(_n,0),n(_n){
        iota(begin(parent),end(parent),0);
    }
    int find(int id){
        if(parent[id] == id) return id;
        return parent[id] = find(parent[id]);
    }
    void merge(int id1,int id2){
        int pid1 = find(id1);
        int pid2 = find(id2);
        if(pid1 == pid2) return;
        parent[pid2] = pid1;
        --n;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU provinces(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(isConnected[i][j])
                    provinces.merge(i,j);
            }
        }
        return provinces.n;
    }
};
