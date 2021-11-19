class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int lo(0),high(nums.size()-1);
        vector<int> ans;
        while(lo<=high)
        {
            if(lo==high)
            {
                ans.push_back(nums[lo]*nums[lo]);
                ++lo;
            }
            else if(abs(nums[lo])>=abs(nums[high]))
            {
                ans.push_back(nums[lo]*nums[lo]);
                ++lo;
            }
            else
            {
                ans.push_back(nums[high]*nums[high]);
                --high;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
