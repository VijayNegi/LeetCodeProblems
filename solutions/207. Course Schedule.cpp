class Solution {
public:
    // self 23ms
    bool canFinish2(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n,0);
        for(auto& p:prerequisites){
            adj[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }
        vector<int> done;
        int result=0;
        for(int i=0;i<n;++i){
            if(inDegree[i]==0){
                done.push_back(i);
            }
        }
        while(done.size()){
            vector<int> next;
            for(auto& course:done){
                for(auto& nextcourse:adj[course]){
                    --inDegree[nextcourse];
                    if(inDegree[nextcourse]==0)
                        next.push_back(nextcourse);
                }
                adj[course].clear();
            }
            result += done.size();
            swap(next,done);
        }
        return result == n;
     }
    // topological sort : 30 ms
    bool canFinish1(int n, vector<vector<int>>& prereq) {

        vector<vector<int>> dep(n);
        vector<int> inbound(n,0);
        for(auto& p:prereq)
        {
            dep[p[1]].push_back(p[0]);
            inbound[p[0]]++;
        }
        list<int> course;
        for(int i=0;i<n;++i)
            if(inbound[i]==0)
                course.push_back(i);
        int done = course.size();
        while(!course.empty())
        {
            int c = course.front();
            course.pop_front();
            for(auto d:dep[c])
            {
                --inbound[d];
                if(inbound[d]==0)
                {
                    course.push_back(d);
                    ++done;
                }
            }
        }
        
        return done == n;
    }
    
    bool iscycle(vector<int> adj[],vector<int> &vis,int id){
        if(vis[id]==1)
            return true;
        if(vis[id]==0){
            vis[id]=1;
            for(auto edge : adj[id]){
                if(iscycle(adj,vis,edge))
                    return true;
            }
        }
        vis[id] = 2;
        return false;
    }
    // detecting cycles
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(iscycle(adj,vis,i))
                return false;
        }
        return true;
    }
};
