class Solution {
public:
    // self: 3 ms
    int wiggleMaxLength1(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || (n==2 && nums[0]!=nums[1]) )
            return n;
        if(n==2 && nums[0]==nums[1])
            return 1;
        vector<int> seq;
        seq.push_back(nums[0]);
        int i=1;
        for(;i<n;++i)
            if(nums[i]!=seq.back())
                break;
        if(i==n)
            return 1;
        seq.push_back(nums[i]);
        bool up = nums[i] > nums[0];
        for(;i<n;++i) {
            if(up && nums[i] < seq.back()) {
                seq.push_back(nums[i]);
                up = !up;
            }
            else if(!up && nums[i] > seq.back()) {
                seq.push_back(nums[i]);
                up = !up;
            }
            else 
                seq.back() = nums[i];
        }
        return seq.size();
    }
    // cleaner O(1);
    int wiggleMaxLength2(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int prev = nums[0];
        int count=1;
        int i=1;
        for(;i<n;++i)
            if(nums[i]!=prev) break;
        if(i==n) return 1;
        prev = nums[i];
        ++count;
        bool up = nums[i] > nums[0];
        for(;i<n;++i) {
            if(up && nums[i] < prev) {
                ++count;
                up = !up;
            }
            else if(!up && nums[i] > prev) {
                ++count;
                up = !up;
            }
            prev = nums[i];
        }
        return count;
    }
    //dp
    int wiggleMaxLength(vector<int>& nums) {
        int size=nums.size(), peak=1, valley=1;
        for(int i=1; i<size; ++i){
                 if(nums[i]>nums[i-1]) peak = valley + 1;
            else if(nums[i]<nums[i-1]) valley = peak + 1;
        }
        return max(peak , valley );
    }
};
