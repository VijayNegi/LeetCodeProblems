            
            for(int i=0;i<n;++i)
            {
                if(!visited[i] && i!=node)
                {
                    int d = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    pq.push({d,i});
                }
            }
        }
        return cost;
    }
    // Prims's clean : 185ms
    int minCostConnectPoints2(vector<vector<int>>& ps) {
        int n = ps.size(), res = 0, i = 0, connected = 0;
        vector<bool> visited(n);
        priority_queue<pair<int, int>> pq;
        while (++connected < n) {
            visited[i] = true;
            for (int j = 0; j < n; ++j)
                if (!visited[j])
                    pq.push({-(abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1])), j});
            while (visited[pq.top().second])
                pq.pop();
            res -= pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return res;
    }
    //Prim's for Complete Graph , track the min distance for each node
    // 100ms
    int minCostConnectPoints(vector<vector<int>>& ps) {
        int n = ps.size(), res = 0, i = 0, connected = 0;
        vector<int> min_d(n, 10000000);
        while (++connected < n) {
            min_d[i] = INT_MAX;
            int min_j = i;
            for (int j = 0; j < n; ++j)
                if (min_d[j] != INT_MAX) {
                    min_d[j] = min(min_d[j], abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]));
                    min_j = min_d[j] < min_d[min_j] ? j : min_j;
                }
            res += min_d[min_j];
            i = min_j;
        }
        return res;
    }
};
