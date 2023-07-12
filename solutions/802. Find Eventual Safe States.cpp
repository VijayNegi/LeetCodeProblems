class Solution {
public:
    // self : 399 ms
    vector<int> eventualSafeNodes1(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> incoming(n);
        for(int i=0;i<n;++i){
            for(auto& destination: graph[i]){
                incoming[destination].push_back(i);
            }
        }
        vector<unordered_set<int>> outgoing(n);
        for(int i=0;i<n;++i){
            outgoing[i].insert(begin(graph[i]),end(graph[i]));
            //outgoing[i].erase(i);
        }
        vector<int> safe;
        for(int i=0;i<n;++i){
            if(outgoing[i].empty())
                safe.push_back(i);
        }
        set<int> result;
        while(safe.size()){
            result.insert(safe.begin(),safe.end());
            vector<int> temp;
            for(auto& i:safe){
                for(auto& d:incoming[i]){
                    outgoing[d].erase(i);
                    if(outgoing[d].empty())
                        temp.push_back(d);
                }
                incoming[i].clear();
            }
            swap(temp,safe);
        }
        
        return {result.begin(),result.end()};
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& G) {
        int N = G.size();
        vector<vector<int>> R(N);
        vector<int> outdegree(N), safe(N), ans;
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            for (int v : G[i]) {
                R[v].push_back(i);
            }
            outdegree[i] = G[i].size();
            if (outdegree[i] == 0) q.push(i);
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            safe[u] = 1;
            for (int v : R[u]) {
                if (--outdegree[v] == 0) q.push(v);
            }
        }
        for (int i = 0; i < N; ++i) {
            if (safe[i]) ans.push_back(i);
        }
        return ans;
    }
};
