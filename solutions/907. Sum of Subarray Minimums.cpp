const int mod = 1e9+7;
class Solution {
public:
    // n2 solution
    int sumSubarrayMins1(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for(int i=0;i<n;++i){
            int subMin = INT_MAX;
            for(int j=i;j<n;++j){
                subMin = min(arr[j],subMin);
                sum += subMin;
                sum %=mod;
            }
        }
        return sum;
    }
    // monotonic stack solution : 209
    int sumSubarrayMins2(vector<int>& arr) {
        vector<int> stk;
        long sumOfMinimums = 0;
​
        // building monotonically increasing stack
        for (int i = 0; i <= arr.size(); i++) {
​
            // when i reaches the array length, it is an indication that
            // all the elements have been processed, and the remaining
            // elements in the stack should now be popped out.
​
            while (!stk.empty() && (i == arr.size() || arr[stk.back()] >= arr[i])) {
​
                int mid = stk.back();
                stk.pop_back();
                int leftBoundary = stk.empty() ? -1 : stk.back();
                int rightBoundary = i;
​
                // count of subarrays where mid is the minimum element
                long count = (mid - leftBoundary) * (rightBoundary - mid) % mod;
​
                sumOfMinimums += (count * arr[mid]) % mod;
                sumOfMinimums %= mod;
            }
            stk.push_back(i);
        }
​
        return (int) (sumOfMinimums);
