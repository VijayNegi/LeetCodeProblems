class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int dist = abs(nums[0]);
        int res = nums[0];
        for(auto& a:nums)
            if(abs(a) < dist)
            {
                dist = abs(a);
                res = a;
            }
            else if(abs(a) == dist)
            {
                res = max(res,a);
            }
        return res;
    }
    int findClosestNumber1(vector<int>& nums) {
    return *min_element(begin(nums), end(nums), [](int a, int b) {
        return abs(a) < abs(b) || (abs(a) == abs(b) && a > b);
    });
}
};
