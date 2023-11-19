class Solution {
public:
    int reductionOperations1(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size()-1;
        int result=0;
        while(n>=0){
            int k = n;
            while(k>=0 && nums[k]==nums[n]) --k;
            if(k >=0)
                result += nums.size() - k-1; 
            n = k;
        }
        return result;
    }
    //sort one
    int reductionOperations(vector<int>& n) {
        int res = 0, sz = n.size();
        sort(begin(n), end(n));
        for (int j = sz - 1; j > 0; --j)
            if (n[j - 1] != n[j])
                res += sz - j;
        return res;
    }
};
