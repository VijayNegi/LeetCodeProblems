class Solution {
public:
    // with priority queue : 372ms
    int constrainedSubsetSum1(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        int sum=INT_MIN;
        auto cmp = [&](int left, int right) { return dp[left] < dp[right]; };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp);
        
        for(int i=0;i<n;++i)
        {
            dp[i] = nums[i];
            if(!pq.empty())
            {
                while(pq.top()< i-k)
                    pq.pop();
                
                dp[i] = max(dp[i],dp[pq.top()]+nums[i]);
            }
            pq.push(i);
            sum = max(sum,dp[i]);
        }
        return sum;
    }
    //with monotonic queue 334ms
    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> dp = nums;
        int sum=INT_MIN;
        deque<int> dq;
        for(int i=0;i<n;++i)
        {
            
            if(!dq.empty())
            {
                while(dq.front()< i-k)
                    dq.pop_front();
                
                dp[i] = max(dp[i],dp[dq.front()]+dp[i]);
            }
            while(!dq.empty() && dp[dq.back()]<= dp[i])
                dq.pop_back();
            dq.push_back(i);
            sum = max(sum,dp[i]);
        }
        return sum;
    }
};
