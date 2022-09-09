class Solution {
public:
    // self 1807 ms
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        map<int,multiset<int>> pmap;
        for(auto& c:prop){
            pmap[c[0]].insert(c[1]);
        }
        int groups = pmap.size();
        vector<int> commu(groups,0);
        auto it = pmap.rbegin();
        int n = groups-1;
        while(it != pmap.rend()) {
            if(n<(groups-1))
                commu[n] = commu[n+1];
            commu[n--] = max(commu[n],*max_element(begin(it->second),end(it->second)));
            ++it;
        }
        int result=0;
        n=0;
        for(auto& g:pmap){
            if(n==(groups-1))
                break;
            
            for(auto& k:g.second) {
                if(k<commu[n+1])
                    ++result;
            }
            ++n;
        }
            
        
        return result;
    }
};
​
