class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> result,end(26,-1);
        
        for(int i=0;i<n;++i)
            end[s[i]-'a'] = i;
​
        int l=0,r=0;
        for(int i=0;i<n;++i)
        {
            r = max(r,end[s[i]-'a']);
            if(r==i)
            {
                result.push_back(r-l+1);
                l = r = i+1;
            }
        }
        return result;
    }
};
