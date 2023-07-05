class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int pre=0,curr=0;
        int res=0;
        for(auto& n:nums){
            if(n==0){
                res = max(res,pre+curr);
                pre = curr;
                curr=0;
            }
            else
                curr++;
        }
        if(curr == nums.size())
            return curr-1;
        else
            res = max(res,pre+curr);
        
        return res;
    }
};
