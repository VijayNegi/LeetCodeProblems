class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr),end(arr));
        int n = arr.size();
        int result = 0;
        for(int i=0;i<n;++i){
            if(arr[i]<=result) continue;
            ++result;
        }
        return result;
    }
};
