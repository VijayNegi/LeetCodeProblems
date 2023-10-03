class Solution {
public:
    // self, WA, because i am only considering full palindroms for center.
    // max possible palindrome for range should be considered.
    long long maxProduct1(string s) {
        int n = s.size();
        vector<int> prePalin(n,1),postPalin(n,1);
        auto palin = manacher_odd(s);
        for(int i=1;i<n;++i){
            prePalin[i] = max(prePalin[i],palin[i/2]);
        }
        for(int i=n-1;i>=0;--i){
            
            int len = n-i-1;
            int center = i+ (len/2);
            postPalin[i] = max(postPalin[i],palin[center]);
            //cout<<i<<" "<<postPalin[i]<<" --  "<< center<<" "<<palin[center] <<endl;
        }
        //cout<<"----"<<endl;
        long result = 0;
        for(int i=0;i<n-1;++i){
            cout<<i<<" "<<prePalin[i]<<" "<<postPalin[i+1]<<endl;
            long l = prePalin[i]*2-1;
            l *= (postPalin[i+1]*2-1);
            result = max(result,l);
        }
        return result;
        
    }
    vector<int> manacher_odd(string s) {
        int n = s.size();
        s = "$" + s + "^";
        vector<int> p(n + 2);
        int l = 1, r = 1;
        for(int i = 1; i <= n; i++) {
            p[i] = max(0, min(r - i, p[l + (r - i)]));
            while(s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if(i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
        return vector<int>(begin(p) + 1, end(p) - 1);
    }
    // https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/discuss/1389958/Manacher-and-Queue
    vector<int> manachers(string s, int n) {
        vector<int> m(n), l2r(n, 1);
        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            int k = (i > r) ? 1 : min(m[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                l2r[i + k] = 2 * k + 1;
                k++;
            }
            m[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        for(int i = 1; i < n; i++) 
            l2r[i] = max(l2r[i], l2r[i - 1]);
        return l2r;
    }
    long long maxProduct(string s) {
        long long res = 1, n = s.size();
        auto l2r = manachers(s, n), r2l = manachers(string(rbegin(s), rend(s)), n);
        for (int i = 0, j = n - 2; i < n - 1; ++i, --j)
            res = max(res, (long long)l2r[i] * r2l[j]);
        return res;
    }
    // check out this solution
    // https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/discuss/1389958/Manacher-and-Queue/1042682
};
// 0 1 2 3 4 5 6 7 8
// z a a a x b b b y
