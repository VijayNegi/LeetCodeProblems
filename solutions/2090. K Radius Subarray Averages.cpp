class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0) return nums;
        int n = nums.size();
        vector<int> result(n,-1);
        int w = k*2+1;
        long sum = 0;
        if(w>n) return result;
        for(int i=-k;i<n-k;++i){
            if(i+k<n) sum += nums[i+k];
            if(i-k-1>=0) sum -= nums[i-k-1];
            if(i+k<n && i-k>=0)
                result[i] = sum/w;
        }
        return result;
    }
};
