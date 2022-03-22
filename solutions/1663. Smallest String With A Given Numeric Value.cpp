class Solution {
public:
    string getSmallestString1(int n, int k) {
        string s;
        for(int i=n;i>0;--i)
        {
            int t = min(k-i,25);
            s += 'a' + t;
            k -=(t+1);
        }
        reverse(begin(s),end(s));
        return s;
    }
    // another way: reverse fill
    string getSmallestString(int n, int k) {
        string res = string(n, 'a');
        k -= n;
        while (k > 0) {
            res[--n] += min(25, k);
            k -= min(25, k);
        }
        return res;
    }
};
