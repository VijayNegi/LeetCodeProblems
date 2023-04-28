struct DSU{
    int s;
    vector<int> parent;
    DSU(int n):s(n),parent(n){
        iota(begin(parent),end(parent),0);
    }
    int find(int id){
        if(parent[id]==id) return id;
        return parent[id] = find(parent[id]);
    }
    void merge(int id1,int id2){
        int pid1 = find(id1);
        int pid2 = find(id2);
        if(pid1 == pid2) return;
        parent[pid2] = pid1;
        --s;
    }
};
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int k = strs[0].size();
        if(k<3) return 1;
        DSU diset(n);
        auto f = [&](string& str1,string& str2){
            int diff=0;
            for(int i=0;i<k;++i)
                if(str1[i]!=str2[i]) ++diff;
            return diff;
        };
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int d =  f(strs[i],strs[j]);
                if(d==0 || d==2)
                    diset.merge(i,j);
            }
            
        }
        return diset.s;
    }
};
