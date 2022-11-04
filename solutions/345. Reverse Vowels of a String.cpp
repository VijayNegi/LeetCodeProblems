class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels{'a','e','i','o','u','A','E','I','O','U'};
        int l=0,r=s.size()-1;
        while(l<r){
            while(l<r && vowels.count(s[l])==0)   ++l;
            if(l>=r) break;
            while(r>l && vowels.count(s[r])==0)   --r;
            if(r<=l) break;
            swap(s[l++],s[r--]);
        }
        return s;
    }
};
