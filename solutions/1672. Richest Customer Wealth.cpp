class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int maxWealth = 0;
        for(auto cus: accounts)
        {
            int wealth = accumulate(cus.begin(),cus.end(),0);
            maxWealth = max(maxWealth, wealth);
        }
        return maxWealth;
    }
};
