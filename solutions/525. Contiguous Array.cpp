class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int,int> hmap;
        int count = 0;
        int n = nums.size();
        int res = 0;
        hmap[0] = -1;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==1)
                ++count;
            else
                --count;
            if(hmap.count(count))
            {
                res = max(res, i- hmap[count]);
            }
            else
                hmap[count] = i;
        }
        return res;
        
    }
};
