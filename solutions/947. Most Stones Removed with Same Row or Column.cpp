struct DSU{
    int count;
    vector<int> parent;
    DSU(int n): parent(n),count(n){
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x){
        if(x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x,int y){
        int px = find(x);
        int py = find(y);
        if(px==py)
            return;
        parent[py] = px;
        --count;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> xSet, ySet;
        for(int i=0;i<n;++i){
            xSet[stones[i][0]].insert(i);
            ySet[stones[i][1]].insert(i);
        }
        DSU dsu(n);
        
        for(int i=0;i<n;++i){
            for(auto x : xSet[stones[i][0]])
                dsu.merge(i,x);
            for(auto y : ySet[stones[i][1]])
                dsu.merge(i,y);
        }
        
        return n- dsu.count;
    }
};
