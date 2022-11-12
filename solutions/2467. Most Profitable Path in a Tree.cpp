class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<unordered_set<int>> adj(n);
        for(auto& v: edges) {
             adj[v[0]].insert(v[1]);
             adj[v[1]].insert(v[0]);
        }
        vector<int> parent(n,-1);
        queue<int> q;
        q.push(0);
        while(q.size()){
            int k = q.front();
            q.pop();
            for(auto& p: adj[k]){
                adj[p].erase(k);  // remove parent from child as this is a tree
                parent[p] = k;
                q.push(p);
            }
        }
​
        // do bfs now from alice
        // <node, income>
        queue<pair<int,int>> alice;
        alice.push({0,0});
        int result = INT_MIN;
        while(alice.size()) {
            int level = alice.size();
            for(int i=0;i<level;++i) {
                auto pos = alice.front();
                alice.pop();
                //cout<<pos.first<<" "<<pos.second<<" "<<amount[pos.first]<<endl;
                if(pos.first == bob)
                    pos.second += amount[pos.first]/2;
                else
                    pos.second += amount[pos.first];
                if(adj[pos.first].empty())
                    result = max(result,pos.second);
​
                for(auto p: adj[pos.first]) {
                    alice.push({p,pos.second});
                }
            }
            if(bob >= 0){
                amount[bob] = 0;
                bob = parent[bob];
            }
        }
        return result;
    }
};
