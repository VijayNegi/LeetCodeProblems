class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<set<int>> pre(n);
        vector<set<int>> dep(n);
        
        for(auto vec: prereq)
        {
            pre[vec[0]].insert(vec[1]); // 1 is pre of 0
            dep[vec[1]].insert(vec[0]);
        }
        
        set<int> cset;
            
        for(int i=0;i<n;++i)
        {
            if(pre[i].empty())
                cset.insert(i);
        }
        
        vector<int> res;
        
        while(!cset.empty())
        {
            set<int> next;
            for(auto c: cset)
            {
                res.push_back(c);
                for(auto d:dep[c])
                {
                    pre[d].erase(c);
                    if(pre[d].empty())
                        next.insert(d);
                }
                
            }
            
            cset = next;
        }
        if(res.size()<n)
            return {};
        return res;
         
    }
};
