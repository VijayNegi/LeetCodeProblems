class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n = nums.size();
        int l,r,res,more;
        l=r=res=more=0;
        while(r<n){
            if(freq[nums[r]]++==k){
                ++more;
            }
            while(more){
                if(freq[nums[l]]-- == k+1)
                    --more;
                ++l;
            }
            res = max(res,r-l+1);
            ++r;
        }
        return res;
    }
};
