class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int c = 0;
        for(auto& ch :s)
            c += ch=='1';
        string result;
        result.append(c-1,'1');
        result.append(n-c,'0');
        result.append(1,'1');
        return result;
    }
};
