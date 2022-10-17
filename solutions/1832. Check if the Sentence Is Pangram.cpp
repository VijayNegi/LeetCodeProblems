class Solution {
public:
    bool checkIfPangram1(string sentence) {
        bool map[26] = {false};
        for(auto& c: sentence)
            map[c-'a'] = true;
        for(auto& b:map)
            if(b==false) return false;
        return true;
    }
    bool checkIfPangram(string sentence) {
        unordered_set<char> seen(sentence.begin(), sentence.end());
        return seen.size() == 26;
    }
};
