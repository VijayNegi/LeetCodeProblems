class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string result;
        string w;
        while(getline(ss,w,' ')){
            if(w.size())
                result = w+ " " + result;
        }
        result.resize(result.size()-1);
        return result;
    }
};
