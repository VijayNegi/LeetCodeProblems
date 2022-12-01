class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.size();
        int count=0;
        for(int i=0;i<n/2;++i)
            if(vowel.count(s[i]))
                ++count;
        for(int i=n/2;i<n;++i)
            if(vowel.count(s[i]))
                --count;
        return count==0;
    }
};
