class Solution {
public:
    // std : 10ms
    int repeatedStringMatch1(string a, string b) {
        
        string temp;
        int bn = b.size();
        int count=0;
        while(temp.size() < bn)
        {
            temp+=a;
            ++count;
        }
        
        if(temp.find(b) != string::npos)
            return count;
        
        temp += a;
        ++count;
        if(temp.find(b) != string::npos)
            return count;
        return -1;
    }
    // circuler match , better on space  1290 ms
    int repeatedStringMatch(string A, string B) {
    for (auto i = 0, j = 0; i < A.size(); ++i) {
        for (j = 0; j < B.size() && A[(i + j) % A.size()] == B[j]; ++j);
        if (j == B.size()) 
            return (i + j - 1) / A.size() + 1;
    }
    return -1;
}
};
