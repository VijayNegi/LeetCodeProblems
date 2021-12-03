class Solution {
public:
    int maxProduct1(vector<int>& nums) {
        
        int maxP = nums[0];
        int currPos = nums[0];
        int currNeg = 0;
        if(currPos<0)
            currNeg = currPos;
        
        for(int i=1;i<nums.size();++i)
        {
            
            if(nums[i]>0)
            {
                if(currPos<=0)
                    currPos = nums[i];
                else
                    currPos *=nums[i];
                
                //if(currNeg<0)
                currNeg *= nums[i];
            }
            else if(nums[i]<0)
            {
                int temp = currPos;
                if(currNeg<0)
                    currPos = currNeg* nums[i];
                else
                    currPos = nums[i];
                //currPos = max(currNeg* nums[i],nums[i]);
                currNeg = min(temp*nums[i],nums[i]);
                // if(currNeg==0)
                //     currNeg = nums[i];
                // else
                //     currNeg *= nums[i];
                
            }
            else
            {
                currPos = 0;
                currNeg = 0;
            }
            maxP = max(maxP,currPos);
        }
        return maxP;
    }
    int maxProduct(vector<int>& nums) {
        // we keep also the minimum-product subarray for the case of multiplying negative with negative
        int max_pro = nums[0];
        int min_save = nums[0];
        int max_save = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // if we got a negative element, we will swap maximum with minimum
            if (nums[i] < 0)
                swap(min_save, max_save);
            min_save = min(nums[i], min_save*nums[i]);
            max_save = max(nums[i], max_save*nums[i]);
            max_pro = max(max_pro, max_save);
        }
        return max_pro;
    }
};
