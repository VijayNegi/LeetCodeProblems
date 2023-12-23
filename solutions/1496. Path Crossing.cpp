class Solution {
public:
    bool isPathCrossing(string path) {
        auto hashf = [](pair<int,int> p){
            return (p.first << 5) + p.second;
        };
        unordered_set<pair<int,int>,decltype(hashf)> seen;
        pair<int,int> curr{0,0};
        seen.insert(curr);
        for(auto& c:path){
            switch(c){
                case 'N': curr.second++; break;
                case 'E': curr.first++; break;
                case 'S': curr.second--; break;
                case 'W': curr.first--;break;
            }
            if(seen.count(curr))
                return true;
            seen.insert(curr);
        }
        return false;
    }
};
