class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        for(auto& n:nums){
            vector<vector<int>> temp;
            for(auto r:res){
                if(r.back()<=n){
                    r.push_back(n);
                    temp.push_back(r);
                }
            }
            temp.push_back({n});
            res.insert( temp.begin(),temp.end());
        }
        vector<vector<int>> result;
        for(auto& r:res)
            if(r.size()>1)
                result.push_back(r);
        return result;
    }
};
