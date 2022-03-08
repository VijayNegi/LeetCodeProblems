class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto& e:edges)
        {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        queue<int> q;
        
        for(int i=0;i<n;++i)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<set<int>> result(n);
        while(!q.empty())
        {
            int t= q.front();
            q.pop();
            
            for(auto n:adj[t])
            {
                if(indegree[n]>0)
                {
                     result[n].insert( result[t].begin(),result[t].end());
                    result[n].insert(t);
                }
                   
                indegree[n]--;
                if(indegree[n]==0)
                {
                    q.push(n);
                }
            }
        }
        vector<vector<int>> sres(n);
        for(int i=0;i<n;++i)
        {
            sres[i].insert(sres[i].end(),result[i].begin(),result[i].end());
        }
        return sres;
        
        
    }
};
