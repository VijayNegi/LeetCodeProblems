class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int n = nums.size();
        vector<int> count(1001,0);
        int result=0;
        for(int i=0;i<n-1;++i)
        {
            if(nums[i]== key)
                count[nums[i+1]]++;
           if(count[result]<count[nums[i+1]])
            result = nums[i+1];     
        }
        return result;
    }
};
