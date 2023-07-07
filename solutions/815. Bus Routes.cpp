    // 1194 ms
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;
        int n = routes.size();
        unordered_map<int,unordered_set<int>> stop2bus;
        
        for(int i=0;i<n;++i){
            for(auto& s:routes[i])
                stop2bus[s].insert(i);
        }
        vector<bool> visited_bus(n,false);
        unordered_set<int> starting(stop2bus[source]);
        unordered_set<int> destination(stop2bus[target]);
        for(auto& b:starting)
            visited_bus[b] = true;
        int path = 1;
        while(starting.size()){
            unordered_set<int> temp;
            for(auto& b:starting){
                if(destination.count(b))
                    return path;
                for(auto& stop: routes[b])
                    for(auto& bus: stop2bus[stop]){
                        if( visited_bus[bus] ) continue;
                        temp.insert(bus);
                        visited_bus[bus] = true;
                    }
            }
            swap(temp,starting);
            ++path;
        }
        return -1;
    }
    // self 2610 ms
    int numBusesToDestination1(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;
        int n = routes.size();
        unordered_map<int,unordered_set<int>> bus2bus;
        unordered_map<int,unordered_set<int>> stop2bus;
        
        
        for(int i=0;i<n;++i){
            for(auto& s:routes[i])
                stop2bus[s].insert(i);
        }
        for(auto& it:stop2bus){
            auto& connected = it.second;
            for(auto& b:connected){
                bus2bus[b].insert(connected.begin(),connected.end());
                bus2bus[b].erase(b);
            }
        }
        vector<bool> visited_bus(n,false);
        unordered_set<int> starting(stop2bus[source]);
        unordered_set<int> destination(stop2bus[target]);
        for(auto& b:starting)
            visited_bus[b] = true;
        int path = 1;
        while(starting.size()){
            unordered_set<int> temp;
            for(auto& b:starting){
