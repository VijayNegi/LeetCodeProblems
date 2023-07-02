class Solution {
public:
    // https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/discuss/866456/Python-Check-All-Combinations/712116
    // 1331 ms
    int maximumRequests1(int n, vector<vector<int>>& requests) {
        int nr = requests.size();
        int ans = 0;
        for (int mask = 0; mask < (1 << nr); mask++){
            vector<int> out(n, 0), in(n, 0);
            for (int i = 0; i < nr; i++){
                if ((mask&(1 << i))){
                    out[requests[i][0]] += 1;
                    in[requests[i][1]] += 1;
                }
            }
            if (out == in){
                int temp = 0; 
                for (auto& v: out) temp += v;
                ans = max(ans, temp);
            }
        }
        return ans;
    }
    // https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/discuss/868403/C%2B%2BPython-knapsack-01
    // 144 ms
    int bal[21] = {};
    int maximumRequests(int n, vector<vector<int>>& requests, int i = 0) {
        if (i == requests.size())
            return count(begin(bal), begin(bal) + n, 0) == n ? 0 : INT_MIN;
        --bal[requests[i][0]];
        ++bal[requests[i][1]];
        auto take = 1 + maximumRequests(n, requests, i + 1);
        ++bal[requests[i][0]];
        --bal[requests[i][1]];
        return max(take, maximumRequests(n, requests, i + 1));
    }
};
