const int LEN = 26;
struct DSU{
    vector<int> parent;
    DSU(int size){
        parent.resize(size,0);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int id){
        if(parent[id]==id)
            return id;
        return parent[id] = find(parent[id]);
    }
    void merge(int id1,int id2){
        int pid1 = find(id1);
        int pid2 = find(id2);
        if(pid1==pid2) return;
        if(pid1<pid2)
            parent[pid2] = pid1;
        else
            parent[pid1] = pid2;
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        DSU dsu(27);
        for(int i=0;i<n;++i)
            dsu.merge(s1[i]-'a',s2[i]-'a');
        string result;
        for(auto& c:baseStr){
            char k = 'a'+ dsu.find(c-'a');
            result.append(1,k);
        }
        return result;
    }
};
