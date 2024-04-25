class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> mem(26,0);
        for(auto& c:s){
            int p = max(c-'a' - k, 0);
            int pmax = min(c-'a' + k,25);
            int val = 0;
            for(int i=p;i<=pmax;++i){
                val = max(val,mem[i]);
            }
            mem[c-'a'] = val +1;
        }
        return *max_element(begin(mem),end(mem));
    }
};
