class Solution {
public:
    // multiset : 393ms
    // Note : Multiset erase with key removes all keys
    int maxOperations1(vector<int>& nums, int k) {
        multiset<int> ms;
        int result=0;
        for(int n:nums)
        {
            auto it = ms.find(k-n);
            if(it != ms.end())
            {
                ms.erase(it);
                ++result;
            }
            else
                ms.insert(n);
        }
        return result;
    }
    // unordered_map: 221 ms
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int result=0;
        for(int n:nums)
        {
            if(mp[k-n]>0)
            {
                --mp[k-n];
                ++result;
            }
            else
                ++mp[n];
        }
        return result;
    }
};
