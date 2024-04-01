class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string last,w;
        while(getline(ss,w,' ')){
            if(w.size())
                last = w;
        }
        return last.size();
    }
};
