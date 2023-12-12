class Solution {
public:
    int findSpecialInteger1(vector<int>& arr) {
        int size = arr.size() / 4;
        for (int i = 0; i < arr.size() - size; i++) {
            if (arr[i] == arr[i + size]) {
                return arr[i];
            }
        }
        return -1;
    }
    // binary
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        vector<int> candidates = {arr[n / 4], arr[n / 2], arr[3 * n / 4]};
        int target = n / 4;
        
        for (int candidate : candidates) {
            int left = lower_bound(arr.begin(), arr.end(), candidate) - arr.begin();
            int right = upper_bound(arr.begin(), arr.end(), candidate) - arr.begin() - 1;
            if (right - left + 1 > target) {
                return candidate;
            }
        }
        
        return -1;
    }
};
