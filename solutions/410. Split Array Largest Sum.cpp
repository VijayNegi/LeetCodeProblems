class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> mem(n+1,vector(m+1,-1));
        function<int(int,int,int)> dfs = [&](int idx,int split,int sum)
        {
            if(mem[idx][split] != -1)
                return mem[idx][split];
            if(split==1)
                return mem[idx][split] = sum;
            int s = 0;
            int result = INT_MAX;
            for(int i=idx;i<=(n-split);++i)
            {
                s += nums[i];
                int res = dfs(i+1,split -1,sum-s);
                result = min(result,max(res,s));
                if(s>result)
                    break;
            }
            return mem[idx][split] = result;
        };
        int sum = accumulate(begin(nums),end(nums),0);
        return dfs(0,m,sum);
    }
};
