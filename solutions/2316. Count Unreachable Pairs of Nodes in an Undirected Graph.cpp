struct DSU{
    vector<int> parent,rank;
    DSU(int _n):parent(_n),rank(_n,1){
        iota(begin(parent),end(parent),0);
    }
    int find(int idx){
        if(parent[idx]==idx) return idx;
        return parent[idx] = find(parent[idx]);
    }
    void merge(int id1,int id2){
        int pid1 = find(id1);
        int pid2 = find(id2);
        if(pid1 == pid2) return;
        parent[pid2] = pid1;
        rank[pid1]+= rank[pid2];
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU uf(n);
        for(auto& e:edges){
            uf.merge(e[0],e[1]);
        }
        long long result=0;
        long long s = n;
        for(int i=0;i<n;++i){
            if(uf.parent[i] == i){
                result += uf.rank[i]*(s-uf.rank[i]);
                s -= uf.rank[i];
            }
        }
        return result;
    }
};
