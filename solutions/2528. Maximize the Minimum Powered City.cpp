// https://leetcode.com/problems/maximize-the-minimum-powered-city/discuss/3014943/C%2B%2BPython-Binary-Search-and-Sliding-Window-and-Greedy-Clear-explanation
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long long left = 0;
        // The answer = `right`, when `r = n`, all value of stations are the same!
        long long right = accumulate(stations.begin(), stations.end(), 0LL) + k;
        long long ans = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (isGood(stations, r, mid, k)) {
                ans = mid; // This is the maximum possible minimum power so far
                left = mid + 1; // Search for a larger value in the right side
            } else {
                right = mid - 1; // Decrease minPowerRequired to need fewer additional power stations
            }
        }
        return ans;
    }
​
    bool isGood(vector<int>& stations, int r, long long minPowerRequired, int additionalStations) {
        int n = stations.size();
        // init windowPower to store power of 0th city (minus stations[r])
        long long windowPower = accumulate(stations.begin(), stations.begin()+r, 0LL);
        vector<int> additions(n, 0);
        for (int i = 0; i < n; i++) {
            if (i + r < n) {
                // now, windowPower stores sum of power stations from [i-r..i+r],
                // it also means it's the power of city `ith`
                windowPower += stations[i + r] + additions[i + r];
            }
