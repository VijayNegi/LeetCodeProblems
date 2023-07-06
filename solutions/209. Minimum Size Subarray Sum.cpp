class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l=0,sum=0,ans=n+1;
        for(int i=0;i<n;++i){
            sum+= nums[i];
            if(sum>=target){
                while(sum>=target){
                    sum-= nums[l++];
                }
                ans = min(ans,i-l+2);
            }
        }
        if(ans >n) return 0;
        return ans;
    }
};
