class Solution {
public:
    bool isBipartite1(vector<vector<int>>& graph) {
        bool curr = false;
        int n = graph.size();
        vector<int> visited(n,false);
        vector<int> colour(n,false);
        for(int i=0;i<n;++i)
        {
            if(visited[i])  continue;
            queue<int> q;
            q.push(i);
            queue<int> p;
            while(!q.empty())
            {
                int k = q.front();
                q.pop();
                visited[k] = true;
                colour[k] = curr;
                for(auto t:graph[k])
                {
                    if(visited[t] && colour[t] == curr)
                        return false;
                    else if(!visited[t])
                        p.push(t);
                }
                if(q.empty())
                {
                    swap(p,q);
                    curr = !curr;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (colors[i]) continue;
            
            colors[i] = 1;
            q.push(i);
            
            while (!q.empty()) {
                int temp = q.front();
                
                for (auto neighbor : graph[temp]) {
                    
                    // Color neighbor with opposite color
                    if (!colors[neighbor]){
                        colors[neighbor] = -colors[temp];
                        q.push(neighbor);
                    }
                    
                    // If the neighbor has the same color - can't bipartite.
                    else if (colors[neighbor] == colors[temp]) 
                        return false;
                }
                q.pop();
            }
        }
        return true;
    }
};
