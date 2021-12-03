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
​
                currNeg *= nums[i];
            }
            else if(nums[i]<0)
            {
                int temp = currPos;
                if(currNeg<0)
                    currPos = currNeg* nums[i];
                else
                    currPos = nums[i];
                currNeg = min(temp*nums[i],nums[i]);
     
                
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
    // optimizing above one
    int maxProduct2(vector<int>& nums) {
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
    // another two pointer approach.
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = nums[0], l = 1, r = 1;
        for (int i = 0; i < n; i++) {
            l =  (l) * nums[i];
            r =  (r) * nums[n - 1 - i];
            res = max(res, max(l, r));
            if(l==0)l=1;
            if(r==0)r=1;
        }
        return res;
    }
​
};
