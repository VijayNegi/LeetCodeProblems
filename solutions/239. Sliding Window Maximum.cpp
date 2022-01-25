class Solution {
public:
    // monotonic queue. 506ms
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        deque<int> dq;
        int i=0;
        for(;i<k;++i)
        {
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        result.push_back(nums[dq.front()]);
        for(;i<n;++i)
        {
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
            result.push_back(nums[dq.front()]);
        }
        return result;
    }
    // cleaned up
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        deque<int> dq;
        for(int i=0;i<n;++i)
        { 
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)
            {
                while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
                result.push_back(nums[dq.front()]);
            } 
        }
        return result;
    }
    // priority queue : 637ms
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        auto cmp = [&](int l,int r){ return nums[l]<nums[r];};
        priority_queue<int,vector<int>, decltype(cmp)> pq(cmp);
        for(int i=0;i<n;++i)
        { 
            pq.push(i);
            if(i>=k-1)
            {
                while(!pq.empty() && pq.top() <= i-k)
                    pq.pop();
                result.push_back(nums[pq.top()]);
            } 
        }
        return result;
    }
};
