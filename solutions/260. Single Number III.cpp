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
        // find one bit set in fullXOR
        while(!(fullXOR & mask) ) mask <<=1;
        int first(0);
        for(auto &n:nums)
        {
            // note : all nums with this set bit will cancel out except one number 
            if(n & mask)
                first ^= n;
        }
        return {first , fullXOR ^ first};
    }
};
