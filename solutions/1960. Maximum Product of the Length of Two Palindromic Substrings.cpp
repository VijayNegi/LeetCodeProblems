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
