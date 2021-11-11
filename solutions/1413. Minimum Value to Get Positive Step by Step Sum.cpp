class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int st(0);
        int sum(0);
        for(int n:nums)
        {
            sum +=n;
            st = min(sum, st);
        }
​
        return -st + 1;
    }
};
