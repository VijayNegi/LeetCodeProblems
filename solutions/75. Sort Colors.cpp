class Solution {
public:
    void sortColors(vector<int>& nums) {
        // we know 1's will be in between
        // so keep track of start of 2's and 1's or end of 0 
        int stTwo(nums.size()),stOne(-1);
        
        int Len(nums.size()-1);
        
        for(int i = 0; i <= Len; i++)
        {
            if(nums[i]==0)
            {
                swap(nums[stOne++ + 1], nums[i]);
            }
            else if(nums[i]==2 && i < stTwo)
            {
                swap(nums[i],nums[stTwo-- - 1]);
                i--;
            }
        }
    }
};
