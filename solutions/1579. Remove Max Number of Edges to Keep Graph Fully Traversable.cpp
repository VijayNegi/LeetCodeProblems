struct UF{
    int n;
    vector<int> parent;
    UF(int k):n(k),parent(k+1){
        iota(begin(parent),end(parent),0);
    }
    int find(int id){
        if(parent[id]==id) return id;
        return parent[id] = find(parent[id]);
    }
    bool merge(int id1,int id2){
        int pid1 = find(id1), pid2 = find(id2);
        if(pid1 == pid2) return false;
        parent[pid2] = pid1;
        --n;
        return true;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> a,b,c;
        for(auto& e:edges){
            if(e[0]==1) a.push_back({e[1],e[2]});
            if(e[0]==2) b.push_back({e[1],e[2]});
            if(e[0]==3) c.push_back({e[1],e[2]});
        }
        UF uf(n);
        int count = 0;
        for(auto& e:c){
            if(!uf.merge(e[0],e[1]))
                ++count;
        }
        UF uf1 = uf;
        for(auto& e:a){
            if(!uf.merge(e[0],e[1]))
                ++count;
        }
        for(auto& e:b){
            if(!uf1.merge(e[0],e[1]))
                ++count;
        }
        if(uf.n != 1 || uf1.n != 1)
            return -1;
        return count;
    }
};
