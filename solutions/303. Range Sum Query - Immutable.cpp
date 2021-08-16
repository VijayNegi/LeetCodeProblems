class NumArray {
    vector<int> comm;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        comm = vector(n+1,0);
        
        for(int i=0;i<n;++i)
        {
            comm[i+1] = comm[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        
        return comm[right+1] - comm[left];
    }
};
​
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
