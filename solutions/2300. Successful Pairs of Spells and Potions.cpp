class Solution {
public:
    vector<int> successfulPairs1(vector<int>& spells, vector<int>& potions, long long success) {
        int sn = spells.size();
        int pn = potions.size();
        vector<int> result;
        sort(begin(potions),end(potions));
        for(auto& s:spells){
            int k = success/s;
            //if(success%s==0) k--;
            int count=0;
            auto p = lower_bound(begin(potions),end(potions),k);
            while(p!=potions.end() && s*1L*(*p)<success)
                ++p;
            if(p!=potions.end()){
                count = distance(p,potions.end());
            }
            result.push_back(count);
        }
        return result;
    }
};
