class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int res=0;
        int ruleId=0;
        if(ruleKey=="color")
            ruleId=1;
        else if(ruleKey=="name")
            ruleId=2;
        for(auto& i:items) {
            if(i[ruleId]==ruleValue)
                ++res;
        }
        return res;
    }
};
