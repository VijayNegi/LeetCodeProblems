class Solution {
public:
    // first attempt : 35 ms
    vector<string> findItinerary1(vector<vector<string>>& tickets) {
        unordered_map<string,int> id2AP;
        unordered_map<int,string> AP2id;
        int id = 0;
        vector<vector<int>> adj(300);
        int n = tickets.size();
        for(int i=0;i<n ; ++i)
        {
            if(id2AP.count(tickets[i][0])==0)
            {
                id2AP[tickets[i][0]] = id++;
                AP2id[id-1] = tickets[i][0];
            }
                
            if(id2AP.count(tickets[i][1])==0)
            {
                id2AP[tickets[i][1]] = id++;
                AP2id[id-1] = tickets[i][1];
            }
                
            adj[id2AP[tickets[i][0]]].push_back(i);
        }
        auto cmp = [&](int l,int r){return (tickets[l][1]< tickets[r][1]);};
        for(auto& a: adj)
            sort(a.begin(),a.end(), cmp);
        
        int beginId = id2AP["JFK"];
        vector<bool> visited(n,false);
        vector<string> result;
        
        function<void(int ap)> dfs = [&](int ap)
        {
           
            for(auto tic : adj[ap])
            {
                if(!visited[tic])
                {
                    visited[tic] = true;
                    dfs(id2AP[tickets[tic][1]]);
                }
            }
            result.push_back(AP2id[ap] ) ;  
        };
        dfs(beginId);
        reverse(result.begin(),result.end());
        return result;
        
    }
    // cleaner 35 ms
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        map<string, multiset<string>> targets;
        vector<string> route;
        
        for (auto ticket : tickets)
            targets[ticket[0]].insert(ticket[1]);
        
        function<void(string)> visit = [&](string airport) 
        {
            while (targets[airport].size()) 
            {
                string next = *targets[airport].begin();
                targets[airport].erase(targets[airport].begin());
                visit(next);
            }
            route.push_back(airport);
        };
        visit("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
​
​
    
};
