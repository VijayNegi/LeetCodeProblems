class Solution {
public:
    // priority solution : 273 ms
    int maxResult1(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        for(int i=1;i<n;++i) {
            while(pq.top().second < i-k) // no need to check size
                pq.pop();
            int s = pq.top().first + nums[i];
            pq.push({s,i}); 
        }
        while(pq.top().second != n-1)
            pq.pop();
        return pq.top().first;
    }
    // monotonic queue solution: 224 ms
    int maxResult(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        deque<int> dq;
        dp[0] = nums[0];
        dq.push_back(0);
        for(int i=1;i<nums.size();i++)
        {
            if(dq.front()+k < i)
                dq.pop_front();
            dp[i] = (dp[dq.front()] + nums[i]);
            
            while(!dq.empty() && dp[dq.back()] < dp[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return dp[nums.size()-1];
    }
};
