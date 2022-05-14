class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto v: times)
            adj[v[0]].push_back({v[1],v[2]});
        
        vector<bool> visited(n+1,false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<> > pq;
        int maxTime=0;
        int count=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int node = p.second;
            int time = p.first;
            if(visited[node])
                continue;
            visited[node] = true;
            ++count;
            maxTime =  max(time,maxTime);
            for(auto e: adj[node]) 
                if(!visited[e.first]) 
                    pq.push({e.second + time,e.first});
        }
        if(count==n)
            return maxTime;
        return -1;
    }
};
