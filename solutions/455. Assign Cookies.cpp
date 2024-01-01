class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g),end(g));
        sort(begin(s),end(s));
        int result=0;
        int idx = 0;
        for(auto& c: s){
            if(c>=g[idx]){
                ++idx;
                ++result;
            }
            if(idx >= g.size()) break;
        }
        return result;
    }
};
