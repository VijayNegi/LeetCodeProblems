struct DSU {
    vector<int> parent;
    DSU(int n):parent(n,0){
        iota(begin(parent),end(parent),0);
    }
    int find(int id){
        if(parent[id] == id) return id;
        return parent[id] = find(parent[id]);
    }
    void merge(int id1, int id2){
        int pid1 = find(id1);
        int pid2 = find(id2);
        if(pid1==pid2) return;
        parent[pid2] = pid1;
        return;
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    void detach(int id1){
        parent[id1] = id1;
    }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(begin(meetings),end(meetings),[](vector<int>& l,vector<int>& r){ return l[2]<r[2];});
        DSU graph(n);
        graph.merge(0,firstPerson);
        int i = 0;
        int m = meetings.size();
        while(i<m){
            int t = meetings[i][2];
           
            int k = i;
            while(k<m && meetings[k][2]==t){
                graph.merge(meetings[k][0],meetings[k][1]);
                ++k;
            }
            while(i<m && meetings[i][2]==t){
               if(!graph.connected(0, meetings[i][0]) ){
                   graph.detach(meetings[i][0]);
                   graph.detach(meetings[i][1]);
               }
                ++i;
            }
        }
        vector<int> result;
        for(int i=0;i<n;++i){
            if(graph.connected(0,i)) result.push_back(i);
        }
        return result;
    }
};
