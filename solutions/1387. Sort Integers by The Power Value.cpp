// https://leetcode.com/problems/sort-integers-by-the-power-value/discuss/547055/C%2B%2B-4-ms-precompute-and-partial-sort
#if 0
int comp[1001] = {0};
class Solution {
    int compute(int i) {
    return i < 2 ? 0 :
        1 + (i % 2 ? compute(i * 3 + 1) : compute(i / 2));
    }
public:
    int getKth(int lo, int hi, int k) {
        if (comp[2] == 0)
            for (auto i = 2; i <= 1000; ++i)
                comp[i] = compute(i);
        vector<int> sorted(hi - lo + 1);
        iota(begin(sorted), end(sorted), lo);
        nth_element(begin(sorted), begin(sorted) + k - 1, end(sorted), [](int i, int j) {
            return comp[i] == comp[j] ? i < j : comp[i] < comp[j]; });
        return sorted[k - 1];
    }
};
#endif
​
// https://leetcode.com/problems/sort-integers-by-the-power-value/discuss/547055/C++-4-ms-precompute-and-partial-sort/820249
// compile time precomputation
static constexpr auto powers = [] {
    std::array<int, 1001> vals{};
    for (size_t i = 1; i < vals.size(); ++i) {
        int steps = 0;
        for (int j = i; j != 1;) {
            if ((j & 1) == 0) {
                j /= 2;
            } else {
                j = 3 * j + 1;
            }
            
            steps++;
        }
        
        vals[i] = steps;
    }
    
    return vals;
}();
​
​
class Solution {
public:
    static int getKth(int lo, int hi, int k) {
        const size_t n = hi - lo + 1;
        std::vector<int> pows(n);
        std::iota(pows.begin(), pows.end(), lo);
​
        std::nth_element(
            pows.begin(), pows.begin() + k - 1, pows.end(),
            [](int a, int b) {
               return powers[a] == powers[b] ? a < b : powers[a] < powers[b]; 
            });
        
        return pows[k - 1];
    }
};
