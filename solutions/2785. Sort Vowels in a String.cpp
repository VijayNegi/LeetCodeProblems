class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vow{'a','e','i','o','u','A','E','I','O','U'};
        map<char,int> count;
        for(auto& c:s){
            if(vow.count(c))
                count[c]++;
        }
        
        auto it = count.begin();
        for(auto& c:s){
            if(vow.count(c)){
                c = it->first;
                it->second--;
                if(it->second==0)
                    ++it;
            }
        }
        return s;
    }
};
