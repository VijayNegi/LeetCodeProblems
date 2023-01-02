class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result;
        int n = s.size(), c=0;
        for(int i=n-1;i>=0;--i){
            if(s[i]=='-')
                continue;
            if(c==k){
                result += "-";
                c=0;
            }
            ++c;
            result += toupper(s[i]);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
