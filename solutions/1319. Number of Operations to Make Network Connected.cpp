struct DSU{
    vector<int> parent;
    int sets;
    DSU(int _n):parent(_n,0),sets(_n){
        iota(begin(parent),end(parent),0);
    }
    int find(int idx){
        if(parent[idx] == idx) return idx;
        return parent[idx] = find(parent[idx]);
    }
    bool merge(int idx1,int idx2){
        int pid1 = find(idx1);
        int pid2 = find(idx2);
        if(pid1 == pid2) return false;
        parent[pid2] = pid1;
        --sets;
        return true;
    }
};
class Solution {
public:
    // Dsu
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU ds(n);
        int edges = 0;
        for(auto& v: connections){
            if(!ds.merge(v[0],v[1]))
                ++edges;
        }
        if(ds.sets <= edges+1)
            return ds.sets-1;
        return -1;
    }
};
