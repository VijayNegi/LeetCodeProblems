class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();++i){
            auto& e = edges[i];
            adj[e[0]].push_back({e[1],succProb[i]});
            adj[e[1]].push_back({e[0],succProb[i]});
        }
        priority_queue<pair<double,int>,vector<pair<double,int>>,less<>> pq;
        pq.push({1,start});
        vector<bool> visited(n,false);
        while(pq.size()){
            auto p = pq.top();
            pq.pop();
            if(visited[p.second]) continue;
            if(p.second==end) return p.first;
            visited[p.second] = true;
            for(auto& ed: adj[p.second]){
                if(visited[ed.first]) continue;
                pq.push({p.first*ed.second,ed.first});
            }
        }
        return 0;
    }
};
