class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> m(501,0);
        for(auto n:nums)
            ++m[n];
        
        for(auto n:m)
            if(n%2)
                return false;
        
        return true;
    }
};
