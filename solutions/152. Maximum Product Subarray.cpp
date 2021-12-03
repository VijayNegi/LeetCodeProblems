class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
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
};
