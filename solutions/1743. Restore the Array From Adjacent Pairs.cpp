class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjP) {
        if(adjP.size()==1)
            return adjP[0];
        unordered_map<int,unordered_set<int>> links;
        int k = 1;
        for(const auto& v:adjP){
            links[v[0]].insert(v[1]);
            links[v[1]].insert(v[0]);
        }
        for(auto& [val,adjset]:links)
            if(adjset.size()==1){
                k = val;
                break;
            }
        vector<int> result{k};
        while(links[k].size()){
            int kn = *links[k].begin();
            links[kn].erase(k);
            k = kn;
            result.push_back(k);
        }
        return result;
    }
};
