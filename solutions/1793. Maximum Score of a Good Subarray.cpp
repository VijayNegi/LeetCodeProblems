class Solution {
public:
    // self
    int maximumScore1(vector<int>& nums, int k) {
        int score = nums[k];
        int n = nums.size();
        int l=k;
        int r=k;
        int low = nums[k];
        while(true){
            if(l>0 && nums[l-1]>=low){
                --l;
                score = max(score,low* (r-l+1));
            }
            else if(r<n-1 && nums[r+1]>=low){
                ++r;
                score = max(score,low* (r-l+1));
            }
            else if(l>0 && r<n-1){
                if(nums[l-1]<= nums[r+1]){
                    ++r;
                    low = min(low,nums[r]);
                    score = max(score,low* (r-l+1));
                }
                else{
                     --l;
                    low = min(low,nums[l]);
                    score = max(score,low* (r-l+1));
                }
            }
            else if(l>0){
