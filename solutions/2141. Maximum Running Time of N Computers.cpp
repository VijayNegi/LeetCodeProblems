class Solution {
public:
    // https://leetcode.com/problems/maximum-running-time-of-n-computers/discuss/1693347/Heap-vs.-Binary-Search
    // https://leetcode.com/problems/maximum-running-time-of-n-computers/discuss/1692939/JavaC%2B%2BPython-Sort-Solution-with-Explanation-O(mlogm)
    long long maxRunTime1(int n, vector<int>& bat) {
        long long sum = accumulate(begin(bat), end(bat), 0LL);
        priority_queue<int> pq(begin(bat), end(bat));
        while (pq.top() > sum / n) {
            sum -= pq.top(); pq.pop();
            --n;
        }
        return sum / n;
    }
    // binary search
    long long maxRunTime(int n, vector<int>& bat) {
        long long l = 0, r = accumulate(begin(bat), end(bat), 0LL) / n;
        while (l < r) {
            long long m = (l + r + 1) / 2, minutes = 0;
            for (int b : bat)
                minutes += min((long long)b, m);
            if (minutes >= n * m)
                l = m;
            else
                r = m - 1;
        }
        return l;
    }
};
​
​
​
​
