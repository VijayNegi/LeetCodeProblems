class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        
        for(const auto n:nums)
        {
            m[n]++;
        }
        vector<int> result;
        for(const auto n:m)
        {
            if(n.second<=1)
                result.push_back(n.first);
        }
        
        return result;
    }
};
