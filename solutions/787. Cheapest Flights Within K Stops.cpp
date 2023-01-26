class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        vector<int> cost(n,INT_MAX);
        queue<pair<int,int>> q;
        q.push({src,0});
        int result=INT_MAX;
        while(q.size()){
            int s = q.size();
            while(s--){
                auto p = q.front();
                q.pop();
                if(p.first==dst){
                    if(p.second < result)
                        result = p.second;
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
};
