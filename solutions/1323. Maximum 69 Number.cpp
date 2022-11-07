class Solution {
public:
    int maximum69Number (int num) {
        string numS  = to_string(num);
        for(auto& c:numS)
            if(c=='6'){
                c ='9';
                break;
            }
        return stoi(numS);
    }
};
