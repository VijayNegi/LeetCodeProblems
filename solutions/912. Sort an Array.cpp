class Solution {
public:
    vector<int> sortArray1(vector<int>& nums) {
        sort(begin(nums),end(nums));
        return nums;
    }
    // tle
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums,0,nums.size()-1);
        return nums;
    }
    void quicksort(vector<int>& nums,int left,int right){
        if(left < right){
            int pivot = partition(nums,left,right);
            quicksort(nums,left,pivot-1);
            quicksort(nums,pivot+1,right);
        }
    }
    int partition(vector<int>& nums,int left,int right){//hoare partition
        int pivot = nums[left], l=left+1, r = right;
        while(l<=r){
            if(nums[l]>pivot && nums[r]<pivot) swap(nums[l++],nums[r--]);
            if(nums[l]<=pivot) ++l;
            if(nums[r]>=pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
