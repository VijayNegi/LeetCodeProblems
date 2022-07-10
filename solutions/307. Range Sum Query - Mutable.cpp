/*
// standared Segment tree implimentation :945 ms
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
        if(left <= sl && sr <= right)           // Note the range comparison
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
*/
/*
// Segment tree impl from cp-algorithms : 865 ms
class NumArray {
    vector<int> nums;
    int n;
    vector<int> t;      // tree
    
public:
    NumArray(vector<int>& _nums):nums(_nums),n(nums.size()),t(4*n,0) {
        build(1,0,n-1);         // Note the root index
    }
    
    void update(int index, int val) {
        //int diff = val - nums[index];
        nums[index] = val;
        update(1,0,n-1,index,val);      // Note the root index
    }
    
    int sumRange(int left, int right) {
        return sum(1,0,n-1,left,right);
    }
private:
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = nums[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm))
               + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
};
*/
// Iterative implimentation : 478 ms
class NumArray {
    vector<int> nums;
    int n;
    vector<int> tree;      // tree
    
public:
    NumArray(vector<int>& _nums):nums(_nums),n(nums.size()),tree(2*n,0) {
        build();         // Note the root index
    }
    
    void update(int pos, int val) {
        pos += n;
        tree[pos] = val;
        while (pos > 0) {
            pos >>= 1; // shift right is the same as divide by 2
            // parent is updated after child is updated
            tree[pos] = tree[2*pos] + tree[2*pos+1];
        }
    }
    
    int sumRange(int l, int r) {
        // get leaf with value 'l'
        l += n;
        // get leaf with value 'r'
        r += n;
        int sum = 0;
        while (l <= r) {
            if ((l % 2) == 1) {  // 'l' is odd, so it is the right child of its parent, then interval includes node 'l' but doesn't include its parent
               sum += tree[l];
               l++;
            }
            if ((r % 2) == 0) {  // 'r' is even, so it is the left child of its parent, then interval includes node 'l' but doesn't include its sibling
               sum += tree[r];
               r--;
            }
            l /= 2;
            r /= 2;
        }
        return sum;
    }
private:
    void build() {
        for (int i = n, j = 0;  i < 2 * n; i++,  j++)
            tree[i] = nums[j];
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
