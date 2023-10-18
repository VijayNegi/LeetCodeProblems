class Solution {
public:
    // self : 395 ms
    int minimumTime1(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto& r:relations){
            adj[r[0]-1].push_back(r[1]-1);
            indegree[r[1]-1]++;
        }
        map<int,vector<int>> progress;
        int t=0;
        for(int i=0;i<n;++i){
            if(indegree[i]==0)
                progress[time[i]].push_back(i);
        }
        while(true){
            auto it = progress.begin();
            int tend = it->first;
            auto vidx = it->second;
            for(auto idx:vidx)
                for(auto& id: adj[idx]){
                    if(--indegree[id]==0){
                        progress[tend + time[id] ].push_back(id);
                    }
                }
            progress.erase(it);
            if(tend> t)
                t = tend;
            if(progress.empty())
                break;
        }
        return t;
    }
    // solution
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) { 
        unordered_map<int, vector<int>> graph;
        vector<int> indegree = vector(n, 0);
​
        for (vector<int>& edge: relations) {
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            graph[x].push_back(y);
            indegree[y]++;
        }
        
        queue<int> queue;
        vector<int> maxTime = vector(n, 0);
        
        for (int node = 0; node < n; node++) {
            if (indegree[node] == 0) {
                queue.push(node);
                maxTime[node] = time[node];
            }
        }
        
        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            for (int neighbor: graph[node]) {
                maxTime[neighbor] = max(maxTime[neighbor], maxTime[node] + time[neighbor]);
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    queue.push(neighbor);
