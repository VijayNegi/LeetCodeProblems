class Solution {
public:
    // self
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> seen;
        long sum=0;
        long pre=0;
        for(auto& n:nums){
            sum += n;
            sum %= k;
            if(seen.count(sum))
                return true;
            seen.insert(pre);
            pre = sum;
        }
        return false;
    }
    bool checkSubarraySum1(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=1;i<n;++i)
        {
            if(i>=2)
                mp[nums[i-2]%k]=1;
            nums[i] += nums[i-1];
            int m = nums[i]%k;
            if(mp[m]==1)
                return true;
        }
        return false;
    }
    // bruteforce : TLE
    bool checkSubarraySum2(vector<int>& nums, int k) {
        vector<int> sums = nums;
        int n= nums.size();
        int m=1;
        while(m<n)
        {
            for(int i=0;i<n-m;++i)
            {
                sums[i] += nums[i+m];
                if(sums[i]%k==0)
                    return true;
            }
            ++m;
        }
        return false;
    }
};
