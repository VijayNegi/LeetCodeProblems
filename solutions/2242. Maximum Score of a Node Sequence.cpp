class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<int>> adj(n);
        for(auto& e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int result=-1;
        
        for(auto& v:adj)
        {
            if(v.size()==0) continue;
            int k = min(3,(int)v.size());
            nth_element(v.begin(), v.begin() + k - 1, v.end(), [&](int l,int r){ return scores[l]>scores[r];});
            v.resize(k);
        }
        
        for(auto& e:edges)
        {
            int base = scores[e[0]] + scores[e[1]];
            for(auto& x: adj[e[0]])
            {
                if(x== e[1]) continue;
                for(auto& y:adj[e[1]])
                {
                    if(y == e[0] || y == x) continue;
                    result = max(result, base + scores[x] + scores[y]);
                }
            }
        }
        return result;
    }
};
