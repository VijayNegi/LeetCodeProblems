class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res{1};
        
        while(res.size() < n)
        {
            vector<int> temp;
            for(auto& a:res)
                if(a*2-1 <= n)
                    temp.push_back(a*2-1);
            for(auto& a:res)
                if(a*2 <= n)
                    temp.push_back(a*2);
            res = temp;
        }
        
        return res;
    }
};
