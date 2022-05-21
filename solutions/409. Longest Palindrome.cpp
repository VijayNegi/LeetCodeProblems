class Solution {
public:
    // 4 ms
    int longestPalindrome1(string s) {
        vector<int> mp(256,0);
        for(auto& c:s)
            mp[c]++;
        bool odd = false;
        int count = 0;
        for(auto k:mp) {
            count += (k/2)*2;
            if(k%2)
                odd = true;
        }
        return count + odd;
    }
    // more optimized
    int longestPalindrome(string s) {
        vector<int> mp(256,0);
        for(auto& c:s)
            mp[c]++;
​
        int count = 0;
        for(auto k:mp) 
            count += (k/2)*2;
        if(count < s.size())
            ++count;
        return count;
    }
};
