class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int hash[26]={};
        int n = words.size();
        if(n<2)
            return true;
        for(int i=0;i<n;++i)
        {
            for(auto c:words[i])
                ++hash[c-'a'];
        }
        for(int i=0;i<26;i++)
        {
            if(hash[i]>0)
                if(hash[i]%n!=0)
                    return false;
        }
        return true;
            
    }
};
