using pi = pair<int,int>;
class Solution {
public:
    // 3 algos , djkastra, bellman ford, floyd warshell
    // 1. djkastra
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // prepare adjacency list 
        vector<vector<pi>> adj(n+1);
        vector<int > dist(n+1,INT_MAX);
        vector<bool> visited(n+1,false);
        dist[k] = 0;
        auto cmp = [](pi left,pi right){return left.second > right.second;};
        priority_queue<pi,vector<pi>, decltype(cmp)> pq(cmp);
        
        for(auto v: times)
        {
            adj[v[0]].push_back({v[1],v[2]});
        }
        
        pq.push({k,0});
        
        while(!pq.empty())
        {
            pi v = pq.top();
            pq.pop();
            if(visited[v.first])
                continue;
            visited[v.first] = true;
            for(auto n: adj[v.first])
            {
                if(visited[n.first])
                    continue;
                if(dist[n.first] > (dist[v.first]+ n.second))
                {
                    dist[n.first] = dist[v.first]+ n.second;
                    pq.push({n.first,dist[n.first]});
                }
                    
            }
        }
​
        int res=0;
        for(int i=1;i<n+1;++i)
        {
            res = max(dist[i],res);
        }
        
        if(res==INT_MAX)
            return -1;
        return res;
        
    }
};
