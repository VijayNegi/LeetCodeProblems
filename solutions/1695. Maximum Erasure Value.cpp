class Solution {
public:
    // sliding window : 198ms
    int maximumUniqueSubarray1(vector<int>& nums) {
        vector<bool> hash(10001,false);
        int sum=0,l=0,r=0;
        int result=0;
        int n= nums.size();
        while(r<n) {
            if(!hash[nums[r]]) {
                hash[nums[r]] = true;
                sum += nums[r++];
                result = max(result,sum);
            }
            else {
                hash[nums[l]] = false;
                sum -= nums[l++];
            }
        }
        return result;
    }
    // hash set : 798ms
    int maximumUniqueSubarray(vector<int>& nums) {        
        int n = size(nums), cur_sum = 0, ans = 0, l = 0, r = 0;
        unordered_set<int> s;
        while(r < n) {
            while(s.find(nums[r]) != end(s))          
                cur_sum -= nums[l], s.erase(nums[l++]);
            cur_sum += nums[r], s.insert(nums[r++]);  
            ans = max(ans, cur_sum);                 
        }
        return ans;
    }
};
