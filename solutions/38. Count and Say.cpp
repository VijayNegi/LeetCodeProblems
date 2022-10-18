class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        if(n==1)
            return result;
        
        for(int i=2;i<=n;++i){
            result = convert(result);
        }
        return result;
    }
    string convert(string s) {
        int count =1,n=s.size();
        string result;
        for(int i=1;i<n;++i) {
            if(s[i] == s[i-1])
                ++count;
            else {
                result += to_string(count);
                result += s[i-1];
                count =1;
            }
        }
        result += to_string(count);
        result += s[n-1];
        return result;
    }
};
