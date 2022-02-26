class Solution {
public:
    vector<int> prefix_function(string s)
    {
        int n = s.size();
        vector<int> pi(n,0);
        int k=0;
        for(int i=1;i<n;++i)
        {
            while(k>0 && s[k]!=s[i])
                k = pi[k-1];
            if(s[k]==s[i])
                ++k;
            pi[k] = k;
        }
        return pi;
    }
    bool match(string& pattern, string& t, vector<int>& pre)
    {
        int p = pattern.size();
        int n = t.size();
        int k=0;
        for(int i=0;i<n;++i)
        {
            while(k>0 && pattern[k] != t[i])
                k = pre[k-1];
            if(pattern[k] == t[i])
                ++k;
            if(k==p)
                return true;
        }
        return false;
    }
    // KMP 10 ms
    vector<string> stringMatching1(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> pre(n);
        for(int i=0;i<n;++i)
            pre[i] = prefix_function(words[i]);
        
        vector<string> result;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==j || (words[j].size() < words[i].size()))
                    continue;
                if(match(words[i],words[j],pre[i]))
                {
                    result.push_back(words[i]);
                    break;
                }
            }
        }
            
        return result;
    }
    // std : 4 ms
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        int n = words.size();
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<n;j++)  
