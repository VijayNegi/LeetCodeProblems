                    continue;
                }
                for(auto& neighbour: adj[p.first]){
                    if(cost[neighbour.first] > p.second+neighbour.second ){
                        q.push({neighbour.first,p.second+neighbour.second});
                        cost[neighbour.first] = p.second+neighbour.second;
                    }
                }
            }
            if(k--<0)
                break;
        }
        return result==INT_MAX?-1:result;
    }
    // official bfs: 64 ms
    int findCheapestPrice2(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : flights) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> dist(n, numeric_limits<int>::max());
        queue<pair<int, int>> q;
        q.push({src, 0});
        int stops = 0;
​
        while (stops <= k && !q.empty()) {
            int sz = q.size();
            // Iterate on current level.
            while (sz--) {
                auto [node, distance] = q.front();
                q.pop();
                // Iterate over neighbors of popped node.
                for (auto& [neighbour, price] : adj[node]) {
                    if (price + distance >= dist[neighbour]) continue;
                    dist[neighbour] = price + distance;
                    q.push({neighbour, dist[neighbour]});
                }
            }
            stops++;
        }
        return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
    }
    // official : Bellmen ford : 107ms
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Distance from source to all other nodes.
        vector<int> dist(n, numeric_limits<int>::max());
        dist[src] = 0;
​
        // Run only K+1 times since we want shortest distance in K hops.
        for (int i = 0; i <= k; i++) {
            // Create a copy of dist vector.
            vector<int> temp(dist);
            for (auto& flight : flights) {
                if (dist[flight[0]] != numeric_limits<int>::max()) {
                    temp[flight[1]] = min(temp[flight[1]], dist[flight[0]] + flight[2]);
                }
            }
            // Copy the temp vector into dist.
            dist = temp;
        }
        return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
    }
};
