class Solution {
public:
    int titleToNumber1(string columnTitle) {
        int n = columnTitle.size();
        int number = 0;
        long mul = 1;
        for(int i=1;i<=n;++i)
        {
            int p = columnTitle[n-i] - 'A'+1;
            number += p*mul;
            mul *= 26;
        }
        return number;
    }
    int titleToNumber(string columnTitle) {
        int colNum = 0;
        for(auto &x: columnTitle)
            colNum = ((26 * colNum) + (x - 'A' + 1));
        return colNum;
    }
};
