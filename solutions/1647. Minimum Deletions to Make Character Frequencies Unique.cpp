class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int,int> seen;
        vector<int> freq(26,0);
        for(auto& c:s){
            freq[c-'a']++;
        }
        int result = 0;
        for(auto& f : freq){
            if(f){
                while(seen.count(f)){
                    --f;
                    ++result;
                }
                if(f>0) seen[f] = 1;
            }
        }
        return result;
    }
};
