class Solution {
public:
    int minReorder(int n, vector<vector<int>>& con) {
        vector<vector<int>> adj(n);
        for(auto& v: con){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(-v[0]);
        }
        vector<bool> visited(n,false);
        visited[0]=true;
        int result=0;
        vector<int> q{0};
        while(q.size()){
            vector<int> next;
            for(auto& node:q){
                for(auto& nei:adj[node]){
                    if(!visited[abs(nei)]){
                        visited[abs(nei)] = true;
                        if(nei>0) ++result;
                        next.push_back(abs(nei));
                    }
                }
            }
            swap(q,next);
        }
        return result;
    }
};
