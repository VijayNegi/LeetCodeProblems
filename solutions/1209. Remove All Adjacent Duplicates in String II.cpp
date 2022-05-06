class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> stk;
        for(auto c:s)
        {
            if(stk.size() && stk.back().first == c)
            {
                int val = stk.back().second +1 ;
                if(val>=k)
                    val = val - k;
                if(val)
                    stk.back().second = val;
                else
                    stk.pop_back();
            }
            else
            {
                stk.push_back({c,1});
            }
            
            while(stk.size() && stk.back().second >=k)
            {
                int val = stk.back().second - k;
                if(val)
                    stk.back().second = val;
                else
                    stk.pop_back();
            }
        }
        string result;
        for(auto p:stk)
        {
            result.append(p.second,p.first);
        }
            
        return result;
    }
};
