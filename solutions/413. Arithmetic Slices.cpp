class Solution {
public:
    // n2 solution
    int numberOfArithmeticSlices1(vector<int>& nums) {
       
        int n = nums.size();
        int result=0;
        for(int i=0;i<n-1;++i)
        {
            int j=i+1;
            int diff = nums[i+1]-nums[i];
            while(j<n && nums[j]-nums[j-1] == diff)
                ++j;
            int count = j-i;
            if(count>2)
                result += count -2;
        }
        return result;
    }
    // o(n) solution
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n<3){
            return 0;
        }
        int ans = 0, count = 0;
        for (int i=1;i<n-1;i++){
            if (nums[i+1]-nums[i]==nums[i]-nums[i-1]){
                count++;
                ans +=count;
            }
            else{
                count = 0;
            }
        }
        return ans;
    }
​
};
