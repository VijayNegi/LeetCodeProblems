class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if(n<3)
            return result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;++i)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int l=i+1,h=n-1;
            while(l<h)
            {
                int sum = nums[i]+nums[l]+nums[h];
                if(sum == 0)
                {
                    
                    result.push_back({nums[i],nums[l],nums[h]});
                    --h;
                    ++l;
                    while((l<h) && (nums[l] == nums[l-1])) l++;
                    while((h>l) && (nums[h] == nums[h+1])) h--;
                    
                }
                else if(sum>0)
                    --h;
                else
                    ++l;
            }
        }
        return result;
    }
};
