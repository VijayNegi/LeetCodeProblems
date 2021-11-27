class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='H')
            {
                if(i+1<n && s[i+1]=='.')
                {
                     ++ans;
                    i+=2;
                }  
                else if(i-1>=0 && s[i-1]=='.')
                    ++ans;
                else
                    return -1;
                
            }
        }
        return ans;
    }
};
