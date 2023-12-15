class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> seen, result;
        for(auto& p:paths){
            seen.insert(p[0]);
            result.erase(p[0]);
            if(!seen.count(p[1]))
                result.insert(p[1]);
        }
        return *result.begin();
    }
};
