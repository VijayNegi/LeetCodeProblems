class Solution {
public:
    //backtrack: TLE
    bool canPartition1(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int n:nums)
            sum+=n;
        sum /=2;
        
        function<bool(int,int)> makesum = [&](int idx,int sum3)
        {   
            if(sum3 == sum)
                return true;
            if(sum3 > sum || idx==n)
                return false;
            
            if(makesum(idx+1,sum3+nums[idx]))
               return true;
            return makesum(idx+1,sum3);
        };
        
        return makesum(0,0);
    }
    //DP: 92 ms
     bool canPartition2(vector<int>& nums) {
        int n = nums.size();
         int m = 0;
         int sum = 0;
         for(auto i:nums)
         {
             sum += i;
             m = max(i,m);
         }
         if( (sum & 1) || m>(sum/2))
             return false;
         sum /=2;
         vector<bool> target(sum+1,false); // dp keeps for each number if it has a subset or not
         target[0] = true;
         for(auto a:nums)
         {
             for(int i=sum;i>=a;--i)
             {
                 target[i] = target[i] || target[i-a];  // for each number, either we use it or we don't
             }
         }
         return target[sum];
     }
    // DP with bitset : 12 ms
    bool canPartition(vector<int>& nums) {
        bitset<10001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (auto n : nums) bits |= bits << n;
        return !(sum & 1) && bits[sum >> 1];
    }
};
