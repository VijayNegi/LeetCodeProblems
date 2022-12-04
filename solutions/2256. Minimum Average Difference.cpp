class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long s=0,ls=0;
        s = accumulate(nums.begin(),nums.end(),s);
        int idx=0,avg=INT_MAX;
        for(int i=0;i<n;++i){
            ls +=nums[i];
            s  -=nums[i];
            int count = (n-i-1)?(n-i-1):1;
            int a = abs(ls/(i+1) - s/count);
            if(a<avg){
                avg = a;
                idx=i;
            }
        }
        return idx;
    }
};
