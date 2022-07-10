class NumArray {
    vector<int> nums;
    int n;
    vector<int> seg;
    
public:
    NumArray(vector<int>& _nums):nums(_nums),n(nums.size()),seg(4*n,0) {
        build(0,0,n-1);
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        update(0,0,n-1,index,diff);
    }
    
    int sumRange(int left, int right) {
        return sumRange(0,0,n-1,left,right);
    }
private:
    void build(int idx,int sl,int sr) {
        if(sl==sr) {
            seg[idx] = nums[sl];
            return;
        }
        int mid = sl + (sr-sl)/2;
        build(2*idx+1,sl,mid);
        build(2*idx+2,mid+1,sr);
        seg[idx] = seg[2*idx+1]+seg[2*idx+2];
    }
    void update(int segIdx, int sl,int sr,int idx,int diff) {
        if(idx < sl || idx > sr)
            return;
        seg[segIdx] += diff;
        if(sl!=sr) {
            int mid = sl + (sr-sl)/2;
            if(idx <= mid)
                update(2*segIdx+1,sl,mid,idx,diff);
            else
                update(2*segIdx+2,mid+1,sr,idx,diff);
        }
    }
    int sumRange(int idx,int sl,int sr,int left, int right) {
        if(right < sl || left > sr)
            return 0;
        if(left <= sl && sr <= right)           // Note the range comparison
            return seg[idx];
        if(sl != sr) 
        {
            int mid = sl + (sr-sl)/2;
            return sumRange(2*idx+1,sl,mid,left,right) +
                    sumRange(2*idx+2,mid+1,sr,left,right);
        }
        return 0;
    }
};
​
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
