class Solution {
    void helper(string s,int idx, string sent, vector<vector<string>>& dict, vector<string>& result)
    {
        int len = s.size();
        if(idx>=len)
        {
            result.push_back(sent);
            return;
        }
        if(idx>0)
            sent+=" ";
        for(auto w: dict[s[idx] -'a'])
        {
            if(w.size()  + idx <= len)
            {
                if(w == s.substr(idx,w.size()))
                {
                    helper(s,idx + w.size() ,sent + w ,dict,result);
                }
            }
        }
        return;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> dict(26,vector<string>());
        
        for(auto w:wordDict)
        {
            dict[w[0]-'a'].push_back(w);
        }
        string sentance;
        vector<string> result;
        helper(s,0,sentance,dict,result);
        
        return result;
    }
};
