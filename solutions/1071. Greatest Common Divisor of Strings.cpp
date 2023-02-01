class Solution {
public:
    vector<int> getPrefix(string& s){
        vector<int> prefix(s.size(),0);
        for(int i=1;i<s.size();++i){
            int j = prefix[i-1];
            while(j>0 && s[i]!=s[j])
                j = prefix[j-1];
            if(s[i]==s[j])
                ++j;
            prefix[i] = j;
            
        }
        return prefix;
    }
    // this is getting smallest factor
    string gcdOfStrings1(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        vector<int> pi1 = getPrefix(str1);
        vector<int> pi2 = getPrefix(str2);
        int k1=0,k2=0;
        for(int i=0;i<n1;++i) if(pi1[i]==0) k1=i+1;
        for(int i=0;i<n2;++i) if(pi2[i]==0) k2=i+1;
        if(n1%k1) k1 = n1;
        if(n2%k2) k2 = n2;
        if(str1.substr(0,k1) == str2.substr(0,k2))
            return str1.substr(0,k1);
        return "";
    }
    string gcdOfStrings2(string str1, string str2) {
        if(str1==str2) return str1;
        if(str2.size() > str1.size()) return gcdOfStrings(str2,str1);
        if(str1.substr(0,str2.size()) == str2) return gcdOfStrings(str2,str1.substr(str2.size()));
        return "";
    }
    // official solution
    string gcdOfStrings(string str1, string str2) {
        // Check if they have non-zero GCD string.
        if (str1 + str2 != str2 + str1) {
            return "";
        }
​
        // Get the GCD of the two lengths.
        int gcdLength = gcd(str1.size(), str2.size());
        return str1.substr(0, gcdLength);
    }
};
