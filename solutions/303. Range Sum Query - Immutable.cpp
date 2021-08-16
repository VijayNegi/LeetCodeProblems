/*class NumArray {
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
};*/
​
class NumArray {
    vector<int> bit;
    int MaxIdx;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        MaxIdx = n +1;
        bit.assign(n+1,0);
        
        for(int i=0;i<n;++i)
        {
            update(i+1,nums[i]);
        }
    }
    void update( int idx, int val)
    {
        while(idx<MaxIdx)
        {
            bit[idx] += val;
            idx += (idx & -idx);
        }
    }
    int read(int idx)
    {
        int sum = 0;
        while(idx>0)
        {
            sum += bit[idx];
            idx -=(idx & -idx);
        }
        return sum;
    }
    
    int sumRange(int left, int right) {
        
        return read(right+1) - read(left);
    }
};
​
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
