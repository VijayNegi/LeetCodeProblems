            size[px] += size[py];
            size[py] = 0;
        }
        
    }
        
};
​
​
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> acMail;
        
        int count = accounts.size();
        DS disjoint(count);
        for(int i=0;i<count;++i)
        {
            for(int j=1;j< accounts[i].size();++j)
            {
                if(acMail.count(accounts[i][j])) // already exist
                {
                    disjoint.unite(acMail[accounts[i][j]], i);
                }
                else
                    acMail[accounts[i][j]] = i;
            }
        }
        
        vector<vector<string>> res;
        unordered_map<int, set<string>> idMail;
        
        for(int i=0;i<count;++i)
        {
            int par = disjoint.find(i);
            for(int j=1;j<accounts[i].size();++j)
            {
                 idMail[par].insert(accounts[i][j]);
            }
        }
        
        for(auto [id,s]: idMail)
        {
            vector<string> vec;
            vec.push_back(accounts[id][0]);
            vec.insert(vec.end(),s.begin(),s.end());
            res.push_back(vec);
        }
        
        return res;
    }
};
