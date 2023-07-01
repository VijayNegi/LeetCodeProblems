class Solution {
public:
    // self : solution through map, reduce two transaction to one
    int minTransfers1(vector<vector<int>>& transactions) {
        vector<vector<int>> tmap(12,vector(12,0));
        for(auto& t:transactions){
            tmap[t[1]][t[0]] = t[2];
        }
        int op =1;
        while(op){
            int temp=0;
            for(int k=0;k<12;++k)
                for(int i=0;i<12;++i)
                    for(int j=0;j<12;++j){
                        if(tmap[i][k] && tmap[k][j]){
                            int m = min(tmap[i][k], tmap[k][j]);
                            tmap[i][k] -=m;
                            tmap[k][j] -=m;
                            tmap[i][j] +=m;
                            ++temp;
                                
                        }
                    }
            op = temp;
        }
        int result = 0;
        for(int i=0;i<12;++i)
            for(int j=0;j<12;++j){
                if(tmap[i][j]) ++result;
            }
        return result;
    }
    // https://leetcode.com/problems/optimal-account-balancing/discuss/95355/Concise-9ms-DFS-solution-(detailed-explanation)
    int minTransfers(vector<vector<int>>& trans) 
    {
        unordered_map<int, long> bal; // each person's overall balance
        for(auto& t: trans) {
          bal[t[0]] -= t[2];
          bal[t[1]] += t[2];
        }
        
        for(auto& p: bal) // only deal with non-zero debts
          if(p.second) debt.push_back(p.second);
          
        return dfs(0);
    }
    
private:
    int dfs(int s) // min number of transactions to settle starting from debt[s]
    { 
        while (s < debt.size() && !debt[s]) ++s; // get next non-zero debt
        
        int res = INT_MAX;
        for (long i = s+1, prev = 0; i < debt.size(); ++i)
          if (debt[i] != prev && debt[i]*debt[s] < 0) // skip already tested or same sign debt
          {
            debt[i] += debt[s]; 
            res = min(res, 1+dfs(s+1)); 
            prev = (debt[i]-=debt[s]);
          }
            
        return res < INT_MAX? res : 0;
    }
    
    vector<long> debt; // all non-zero debts
};
