class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0),index(26,-1);
        for(int i=0;i<s.size();++i) {
            int k = s[i]-'a';
            freq[k]++;
            index[k]= i;
        }
        int result=INT_MAX;
        for(int i=0;i<26;++i) {
            if(freq[i]==1 && index[i]<result)
                result=index[i];
        }
        return (result == INT_MAX)? -1: result;
    }
};
