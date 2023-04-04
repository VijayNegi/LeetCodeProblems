class Solution {
public:
    int partitionString1(string s) {
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
    int partitionString(string s) {
        vector<int> lastSeen(26, -1);
        int count = 1, substringStart = 0;
​
        for (int i = 0; i < s.length(); i++) {
            if (lastSeen[s[i] - 'a'] >= substringStart) {
                count++;
                substringStart = i;
            }
            lastSeen[s[i] - 'a'] = i;
        }
​
        return count;
    }
};
