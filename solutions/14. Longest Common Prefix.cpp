class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int i=0;
        int n = strs.size();
        while(true)
        {
            if(i>= strs[0].size())
                return strs[0].substr(0,i);
            for(int k=1;k<n;++k)
            {
                if(i>= strs[k].size())
                    return strs[0].substr(0,i);
                if(strs[k][i]!= strs[0][i])
                    return strs[0].substr(0,i);
            }
            ++i;
        }
        return strs[0].substr(0,i);
    }
};
