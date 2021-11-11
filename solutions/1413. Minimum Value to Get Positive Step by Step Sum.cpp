class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int st(INT_MAX);
        int sum(0);
        for(int n:nums)
        {
            sum +=n;
            st = min(sum, st);
        }
        
        if(st>=1)
            st=1;
        else
            st = abs(st) +1;
        return st;
    }
};
