class DS
{
public:
    vector<int> parent;
    vector<int> size;
    
    DS(int _size): parent(_size), size(_size,1)
    {
        for(int i =0;i< parent.size();++i)
            parent[i] = i;
    }
    
    int find(int k)
    {
        if(parent[k]==k)
            return k;
        return parent[k] = find(parent[k]); // path optimization
    }
    
    void unite(int x,int y)
    {
        int px = find(x);
        int py = find(y);
        if(px == py)
            return;     // nothing to unite
        if(size[px]< size[py])
        {
            parent[px] = py;
            size[py] += size[px];
            size[px] = 0;
        }
        else
        {
            parent[py] = px;
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
        unordered_map<string, int> mail2acc;
        
        int count = accounts.size();
        DS disjoint(count);
        for(int i=0;i<count;++i)
        {
            for(int j=1;j< accounts[i].size();++j)
            {
                if(mail2acc.count(accounts[i][j])) // already exist
                {
                    disjoint.unite(mail2acc[accounts[i][j]], i);
                }
                else
                    mail2acc[accounts[i][j]] = i;
            }
        }
        
        vector<vector<string>> res;
        unordered_map<int, set<string>> acc2MailSet;
        
        // for(int i=0;i<count;++i)
        // {
        //     int par = disjoint.find(i);
        //     for(int j=1;j<accounts[i].size();++j)
        //     {
        //          idMail[par].insert(accounts[i][j]);
        //     }
        // }
        
        for(auto [mail,acc]: mail2acc)
        {
            int par = disjoint.find(acc);
            acc2MailSet[par].insert(mail);
            
        }
        
        for(auto [acc,s]: acc2MailSet)
        {
            vector<string> vec;
            vec.push_back(accounts[acc][0]);
            vec.insert(vec.end(),s.begin(),s.end());
            res.push_back(vec);
        }
        
        return res;
    }
};
