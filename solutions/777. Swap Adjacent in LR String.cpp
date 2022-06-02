class Solution {
public:
    //https://leetcode.com/problems/swap-adjacent-in-lr-string/discuss/113787/C%2B%2B-with-explanation-O(n)-14ms
    bool canTransform(string s1, string s2) {
        int n = s1.size();
        int i = -1, j = -1;
        while (true) {
            while (++i < n && s1[i] == 'X');
            while (++j < n && s2[j] == 'X');
​
            int quit = (i == n) + (j == n);
            if (quit) return quit == 2;
    
            if (s1[i] != s2[j] || (s1[i] == 'L' ? i < j : i > j))
                return false;
        }
        return true;
    }
};
