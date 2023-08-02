class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        vector<int> curr;
        function<void(int)> dfs = [&](int k){
            if(k==n){
                result.push_back(curr);
                return;
            }
            for(int i=0;i<n;++i){
                if(nums[i]==-11)
                    continue;
                curr.push_back(nums[i]);
                nums[i]=-11;
                dfs(k+1);
                nums[i] = curr.back();
                curr.pop_back();
            }
        };
        dfs(0);
        return result;
    }
};
