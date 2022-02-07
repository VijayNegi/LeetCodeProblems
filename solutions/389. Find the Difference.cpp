class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hash(26,0);
        
        for(auto a:s)
            hash[a-'a']--;
        for(auto a:t)
            hash[a-'a']++;
        
        char c='a';
        for(int i=0;i<26;++i)
            if(hash[i]>0)
            {
                c +=i; 
                break;
            }
        return c;
    }
};
