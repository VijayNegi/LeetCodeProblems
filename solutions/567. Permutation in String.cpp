class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(), n2 = s2.size();
        if(n2<n1)
            return false;
        
        int hmap1[26] = {0};
        int hmap2[26] = {0};
        
        auto cmp = [&]()->bool
        {
            for(int i=0;i<26;++i)
                if(hmap1[i]!=hmap2[i])
                    return false;
            return true;
        };
        
        for(int i=0;i<n1;++i)
        {
            hmap1[s1[i]- 'a']++;
            hmap2[s2[i]- 'a']++;
        }
        
        if(cmp())
            return true;
        
        for(int i=n1;i<n2;++i)
        {
            hmap2[s2[i]- 'a']++;
            hmap2[s2[i-n1]- 'a']--;
            if(cmp())
                return true;
        }
        
        return false;
    }
};
