class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carry=0,i=0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        while( i<a.size() || i<b.size()){
            int x = i<a.size()? a[i]-'0':0;
            int y = i<b.size()? b[i]-'0':0;
            carry += x+y;
            result.push_back('0'+carry%2);
            carry /= 2;
            ++i;
        }
        if(carry)
            result.push_back('1');
        reverse(result.begin(),result.end());
        return result;
    }
};
