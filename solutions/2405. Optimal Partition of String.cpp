class Solution {
public:
    int partitionString(string s) {
        vector<int> f(26,0);
        int result=1;
        for(auto& c:s){
            if(f[c-'a']){
                ++result;
                fill(begin(f),end(f),0);
            }
            f[c-'a']++;
        }
        return result;
    }
};
