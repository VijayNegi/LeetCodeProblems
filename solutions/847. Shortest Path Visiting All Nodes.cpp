using pi = pair<int,int>;
class Solution {
public:
    // basically smart bfs : what smart ?? visit state i.e what nodes are visited prior to visiting this node(to avoid loop).
    int shortestPathLength(vector<vector<int>>& graph) {
        unordered_set<int> visited;    // node, state
        queue<pi> que;
        int n = graph.size();
        for(int i=0;i<n;++i)
        {
            pi p{i,1<<i};
            que.push(p);
            int hash = (1<<(i+12)) | p.second ; 
            visited.insert(hash);
        }
        int cost = 0;
        int endState = (1<< n) - 1;
        int count = que.size();
        while(que.size())
        {
            if(count == 0 )
            {
                count = que.size();
                ++cost;
            }
            
            pi curr = que.front();
            que.pop();
            --count;
            if(curr.second == endState)
                return cost;
            
            for(auto nei: graph[curr.first])
            {
                int state = curr.second | (1 << nei);
                int hash = (1<<(nei+12)) | state; 
                pi p{nei, state };
               
                if(visited.insert(hash).second)
                {
                    que.push(p);
                }
            }
        }
        
        return -1;
    }
};
