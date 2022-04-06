class Solution {
public:
    // nth_elements : 4 ms
    int findKthLargest1(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
    // partial_sort : 15ms
    int findKthLargest2(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    }
    // min heap :  4 ms
    int findKthLargest3(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
    // min heap multiset :  4 ms
    int findKthLargest4(vector<int>& nums, int k) {
        multiset<int> mset;
        for (int num : nums) {
            mset.insert(num);
            if (mset.size() > k) {
                mset.erase(mset.begin());
            }
        }
        return *mset.begin();
    }
    //https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort
    // check randPiot solutoin :https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C++-STL-partition-and-heapsort/61538
    // quick select : 169ms
    int findKthLargest5(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, kth;
        while (true) {
            int idx = partition4(nums, left, right);
            if (idx == k - 1) {
                kth = nums[idx];
                break;
            }
            if (idx < k - 1) {
                left = idx + 1;
            } else {
                right = idx - 1;
            }
        }
        return kth;
    }

    int partition4(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
    
    // check https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60294/Solution-explained/267106
    // just copied it to check if it worked
    int partition1(vector<int>& nums, int lo, int hi) {
        int pivot = nums[hi];
        int i = lo;
        for (int j = lo; j < hi; j++) {
            if (nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[hi]);
        return i;
    }
    
    
    // ********
    //https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/893847/C%2B%2B-Ten-Solutions
    // maybe to memorize
    int findKthLargest(vector<int>& nums, int k) {
        //partition rule: >=pivot   pivot   <=pivot
        int left=0,right=nums.size()-1,idx=0;
        while(1){
            idx = partition(nums,left,right);
            if(idx==k-1) break;
            else if(idx < k-1) left=idx+1;
            else right= idx-1;
        }
        return nums[idx];
    }
    int partition(vector<int>& nums,int left,int right){//hoare partition
        int pivot = nums[left], l=left+1, r = right;
        while(l<=r){
            if(nums[l]<pivot && nums[r]>pivot) swap(nums[l++],nums[r--]);
            if(nums[l]>=pivot) ++l;
            if(nums[r]<=pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }

};
