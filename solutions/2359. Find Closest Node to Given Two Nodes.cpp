                int t = n1;
                n1 = edges[n1];
                edges[t] = -1;
            }
            if(edges[n2]>=0){
                s2.insert(edges[n2]);
                int t = n2;
                n2 = edges[n2];
                edges[t] = -1;
            }
            if(s1.count(n2) && s2.count(n1)){
                return n1<n2? n1:n2;
            }
            else if(s1.count(n2) )
                return n2;
            else if(s2.count(n1))
                return n1;
        }
        return -1;
    }
    // official: 191ms 
    void bfs(int startNode, vector<int>& edges, vector<int>& dist) {
        int n = edges.size();
        queue<int> q;
        q.push(startNode);
​
        vector<bool> visit(n);
        dist[startNode] = 0;
​
        while (!q.empty()) {
            int node = q.front();
            q.pop();
​
            if (visit[node]) {
                continue;
            }
​
            visit[node] = true;
            int neighbor = edges[node];
            if (neighbor != -1 && !visit[neighbor]) {
                dist[neighbor] = 1 + dist[node];
                q.push(neighbor);
            }
