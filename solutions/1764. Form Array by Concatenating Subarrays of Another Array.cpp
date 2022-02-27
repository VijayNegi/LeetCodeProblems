class Solution {
    vector<int> prefix(vector<int> s)
    {
        int n = s.size();
        vector<int> pi(n,0);
        int k=0;
        for(int i=1;i<n;++i)
        {
            while(k>0 && s[i]!=s[k])
                k = pi[k-1];
            if(s[i]==s[k])
                ++k;
            pi[i] = k;
        }
        return pi;
    }
    int match(vector<int>& s, vector<int>& p, int start)
    {
        int n = s.size();
        int np = p.size();
        vector<int> pi = prefix(p);
        int k=0;
        for(int i=start;i<n;++i)
        {
            while(k>0 && s[i]!=p[k])
                k = pi[k-1];
            if(s[i]==p[k])
                ++k;
            if(k==np)
                return i-np+1;
        }
        return -1;
        
    }
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int start=0;
        for(auto& g:groups)
        {
            start = match(nums,g,start);
            if(start == -1)
                return false;
            start+= g.size();
        }
        return true;
    }
};
