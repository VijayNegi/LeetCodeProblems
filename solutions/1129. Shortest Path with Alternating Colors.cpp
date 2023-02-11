class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> result(n,-1);
        //result[0]=0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e:redEdges){
            adj[e[0]].push_back({e[1],2});
        }
        for(auto& e:blueEdges){
            adj[e[0]].push_back({e[1],1});
        }
        vector<int> visited(n,0);
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});
        int dist = 0;
        while(q.size()){
            int s = q.size();
            while(s--){
                auto n = q.front();
                q.pop();
                if(visited[n.first] & n.second)
                    continue;
                visited[n.first] |= n.second;
                if(result[n.first] == -1){
                    result[n.first] = dist;
                    for(auto nei: adj[n.first]){
                        if(nei.second != n.second)
                            q.push(nei);
                    }
                }
                else {
                    for(auto nei: adj[n.first])
                        if(nei.second != n.second)
                            q.push(nei);
                }
            }
            ++dist;
        }
        return result;
    }
};
