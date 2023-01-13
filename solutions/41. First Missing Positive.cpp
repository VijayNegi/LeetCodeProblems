class Solution {
public:
    // 63 ms
    int firstMissingPositive1(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]>0 && nums[i]<=n){
                int idx = nums[i]-1;
                if(nums[i] != nums[idx]){
                    swap(nums[i],nums[idx]);
                    if(idx > i) --i;
                }
            }
        }
        for(int i=1;i<=n;++i){
            if(nums[i-1]!=i) return i;
        }
        return n+1;
    }
    //more clean 52 ms
    int firstMissingPositive2(vector<int>& A)
    {
        int n = A.size();
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);
        
        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;
        
        return n + 1;
    }
    // 39 ms
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) if (nums[i] <= 0) nums[i] = n + 1;
        for (int i = 0; i < n; i++) if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1;
        for (int i = 0; i < n; i++) if (nums[i] > 0) return i + 1;
        return n + 1;
    }
};
