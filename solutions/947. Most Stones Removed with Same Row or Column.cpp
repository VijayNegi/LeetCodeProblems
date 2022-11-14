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
// Why topological sort wont work for this
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/discuss/197668/Count-the-Number-of-Islands-O(N)
class Solution {
public:
    // disjoint set solution - 104 ms
    int removeStones1(vector<vector<int>>& stones) {
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
    // DFS solution  551 ms
    int dfs(vector<vector<int>>&stones,int index,vector<bool>&visited,int&n){
        visited[index]=true;
        int result=0;
        for(int i=0;i<n;i++)
            if(!visited[i]&&(stones[i][0]==stones[index][0]||stones[i][1]==stones[index][1]))
                result +=(dfs(stones,i,visited,n) + 1);
        return result;
    }
    int removeStones(vector<vector<int>>&stones) {
        int n = stones.size();
        vector<bool>visited(n,0);
        int result=0;
        for(int i=0;i<n;i++){
            if(visited[i]){continue;}
            result+=dfs(stones,i,visited,n);
        }
        return result;
    }
};
