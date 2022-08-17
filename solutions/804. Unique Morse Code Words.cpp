class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> vec{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> unique;
        
        for(auto& w:words) {
            string s;
            for(auto& c:w) {
                s += vec[c-'a'];
            }
            unique.insert(s);
        }
        return unique.size();
    }
};
