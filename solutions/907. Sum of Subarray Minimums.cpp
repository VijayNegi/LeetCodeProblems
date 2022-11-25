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

        // building monotonically increasing stack
        for (int i = 0; i <= arr.size(); i++) {

            // when i reaches the array length, it is an indication that
            // all the elements have been processed, and the remaining
            // elements in the stack should now be popped out.

            while (!stk.empty() && (i == arr.size() || arr[stk.back()] >= arr[i])) {

                int mid = stk.back();
                stk.pop_back();
                int leftBoundary = stk.empty() ? -1 : stk.back();
                int rightBoundary = i;

                // count of subarrays where mid is the minimum element
                long count = (mid - leftBoundary) * (rightBoundary - mid) % mod;

                sumOfMinimums += (count * arr[mid]) % mod;
                sumOfMinimums %= mod;
            }
            stk.push_back(i);
        }

        return (int) (sumOfMinimums);
    }
    // DP+monotonic stack :214 ms
    int sumSubarrayMins(vector<int>& arr) {

        vector<int> stk;

        // make a dp array of the same size as the input array `arr`
        vector<int> dp(arr.size());

        // making a monotonic increasing stack
        for (int i = 0; i < arr.size(); i++) {
            // pop the stack until it is empty or
            // the top of the stack is greater than or equal to
            // the current element
            while (!stk.empty() && arr[stk.back()] >= arr[i]) {
                stk.pop_back();
            }

            // either the previousSmaller element exists
            if (stk.size() > 0) {
                int previousSmaller = stk.back();
                dp[i] = dp[previousSmaller] + (i - previousSmaller) * arr[i];
            } else {
                // or it doesn't exist, in this case the current element
                // contributes with all subarrays ending at i
                dp[i] = (i + 1) * arr[i];
            }
            // push the current index
            stk.push_back(i);
        }

        // Add all elements of the dp to get the answer
        long sumOfMinimums = 0;
        for (int count : dp) {
            sumOfMinimums += count;
            sumOfMinimums %= mod;
        }

        return (int) sumOfMinimums;
    }
};
