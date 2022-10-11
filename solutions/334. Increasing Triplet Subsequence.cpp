class Solution {
public:
    bool increasingTriplet1(vector<int>& nums) {
        //priority_queue<int> pq;
        vector<int> v;
        for(auto& i:nums) {
            auto it = lower_bound(v.begin(),v.end(),i);
            if(it!=v.end())
                *it = i;
            else
                v.push_back(i);
            if(v.size()>=3)
                return true;
        }
        return false;
    }
    // simple LIS
    bool increasingTriplet(vector<int>& nums) {
        int one = INT_MAX, two = INT_MAX;
        for (auto num : nums) {
            if (num <= one)
                one = num;
            else if (num <= two)
                two = num;
            else 
                return true;
        }
        return false;
    }
       
};
