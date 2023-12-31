class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> first(26,-1);
        int result=-1;
        for(int i=0;i<s.size();++i){
            if(first[s[i]-'a']!=-1)
                result = max(result, i-first[s[i]-'a']-1);
            else
                first[s[i]-'a'] = i;
        }
        return result;
    }
};
