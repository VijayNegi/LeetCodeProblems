class Solution {
public:
    // hashmap
    vector<int> singleNumber1(vector<int>& nums) {
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
    
    //bit manupulation
    vector<int> singleNumber(vector<int>& nums) {
        int fullXOR(0);
        
        for(auto &n:nums)
            fullXOR ^= n;
        
        int mask(1);
        while(!(fullXOR & mask) ) mask <<=1;
        int first(0);
        for(auto &n:nums)
        {
            if(n & mask)
                first ^= n;
        }
        return {first , fullXOR ^ first};
    }
};
