class Solution {
public:
    //contest: 268 ms
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string,int> map_res;//(recipes.begin(),rescipes.end());
        for(int i=0;i<n;++i)
        {
            map_res[recipes[i]] = i;
        }
        unordered_set<string> set_sup(supplies.begin(),supplies.end());
        
        vector<int> inbound(n,0);
        vector<vector<int>> depends(n);
        
        for(int i=0;i<n;++i)
        {
            for(auto& ing: ingredients[i])
            {
                if(map_res.count(ing))
                {
                    ++inbound[i];
                    depends[map_res[ing]].push_back(i);
                }
                    
            }
        }
        vector<int> make;
        for(int i=0;i<n;++i)
        {
            if(inbound[i]==0)
                make.push_back(i);
        }
        
        vector<string> result;
        while(!make.empty())
        {
            vector<int > next;
            for(auto r:make)
            {
                int count = 0;
                for(auto i:ingredients[r])
                {
                    if(!set_sup.count(i))
                        break;
                    ++count;
                }
                if(count == ingredients[r].size())
                {
                    result.push_back(recipes[r]);
                    set_sup.insert(recipes[r]);
                    
                    for(int d=0;d< depends[r].size();++d)
                    {
                        int tr = depends[r][d];
                        --inbound[tr];
                        if(inbound[tr]==0)
                            next.push_back(tr);
                    }
                }
            }
            make = next;
        }
        
        return result;
    }
};
