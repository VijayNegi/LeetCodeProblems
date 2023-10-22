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
                 --l;
                low = min(low,nums[l]);
                score = max(score,low* (r-l+1));
            }
            else if(r<n-1){
                 ++r;
                    low = min(low,nums[r]);
                    score = max(score,low* (r-l+1));
            }
            else break;
        }
        return score;
    }
    // same but concise
        int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int left = k;
        int right = k;
        int ans = nums[k];
        int currMin = nums[k];
        
        while (left > 0 || right < n - 1) {
            if ((left > 0 ? nums[left - 1]: 0) < (right < n - 1 ? nums[right + 1] : 0)) {
                right++;
                currMin = min(currMin, nums[right]);
            } else {
                left--;
                currMin = min(currMin, nums[left]);
            }
            
            ans = max(ans, currMin * (right - left + 1));
        }
        
        return ans;
    }
};
