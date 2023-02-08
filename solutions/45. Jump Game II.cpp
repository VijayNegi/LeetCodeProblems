class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> jumps(n,numeric_limits<int>::max());
        jumps[0]=0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<=(i+nums[i]) && j<n;++j){
                jumps[j] = min(jumps[j],jumps[i]+1);
            }
        }
        return jumps[n-1];
    }
};
