class Solution {
public:
    int countHomogenous(string s) {
        const int mod = 1e9+7;
        char prev = '1';
        int curr = 0,result = 0;;
        for(auto& c:s){
            if(c == prev){
                ++curr;
            }
            else{
                prev = c;
                curr = 1;
            }
            result += curr;
            result %= mod;
        }
        return result;
    }
};
