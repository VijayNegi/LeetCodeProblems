class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,pair<int,int>> range;
        for(int i=0;i<s.size();++i){
            if(range.count(s[i])){
                range[s[i]].second = i;
            }
            else{
                range[s[i]] = {i,i};
            }
        }
        int result=0;
        for(auto& itr: range){
            char c = itr.first;
            int st = itr.second.first;
            int ed = itr.second.second;
            if(st+1<ed){
                unordered_set<char> unq(s.begin()+st+1,s.begin()+ed);
                result += unq.size();
            }
        }
        return result;
    }
};
