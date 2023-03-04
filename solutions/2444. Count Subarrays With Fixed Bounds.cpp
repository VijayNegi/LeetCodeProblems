class Solution {
public:
    // brute force
    long long countSubarrays1(vector<int>& nums, int minK, int maxK) {
        long long result = 0;
        int low=INT_MAX,high=0,n=nums.size();
        for(int i=0;i<n;++i){
            low=INT_MAX;
            high=0;
            for(int j=i;j<n;++j){
                if(nums[j]<minK || nums[j]>maxK) break;
                low = min(low,nums[j]);
                high = max(high,nums[j]);
                if(low == minK && high==maxK)
                    ++result;
            }
        }
        return result;
    }
    // O(n)
    // https://leetcode.com/problems/count-subarrays-with-fixed-bounds/discuss/2708099/JavaC%2B%2BPython-Sliding-Window-with-Explanation
    long long countSubarrays(vector<int>& A, int minK, int maxK) {
        long res = 0, jbad = -1, jmin = -1, jmax = -1, n = A.size();
        for (int i = 0; i < n; ++i) {
            if (A[i] < minK || A[i] > maxK) jbad = i;
            if (A[i] == minK) jmin = i;
            if (A[i] == maxK) jmax = i;
            res += max(0L, min(jmin, jmax) - jbad);
        }
        return res;
    }
};
