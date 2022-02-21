class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int maj;
        for(auto n:nums)
        {
            if(count==0)
                maj = n;
            count += (maj == n)? +1:-1;
        }
        return maj;
    }
};
