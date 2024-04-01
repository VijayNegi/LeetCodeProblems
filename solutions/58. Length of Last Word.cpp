class Solution {
public:
    int lengthOfLastWord1(string s) {
        stringstream ss(s);
        string last,w;
        while(getline(ss,w,' ')){
            if(w.size())
                last = w;
        }
        return last.size();
    }
    int lengthOfLastWord(string s) { 
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') tail--;
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }
    int lengthOfLastWord2(string s) {  
        stringstream ss(s);  
        string temp;  
        while(ss>>temp){}  
        return temp.size();  
    }
};
