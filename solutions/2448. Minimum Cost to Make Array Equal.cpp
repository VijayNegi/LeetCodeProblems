class Solution {
public:
    // Prefix Sum
    long long minCost1(vector<int>& nums, vector<int>& cost) {
        // Sort integers by values.
        int n = nums.size();
        vector<vector<int>> numsAndCost(n,vector(2,0));
        for (int i = 0; i < n; ++i) {
            numsAndCost[i][0] = nums[i];
            numsAndCost[i][1] = cost[i];
        }
        sort(begin(numsAndCost), end(numsAndCost));
​
        // Get the prefix sum array of the costs.
        vector<long> prefixCost(n,0);
        prefixCost[0] = numsAndCost[0][1];
        for (int i = 1; i < n; ++i)
            prefixCost[i] = numsAndCost[i][1] + prefixCost[i - 1];
​
        // Then we try every integer nums[i] and make every element equals nums[i],
        // Start with nums[0]
        long totalCost = 0l;
        for (int i = 1; i < n; ++i)
            totalCost += 1l * numsAndCost[i][1] * (numsAndCost[i][0] - numsAndCost[0][0]);
        long answer = totalCost;
        
        // Then we try nums[1], nums[2] and so on. The cost difference is made by the change of
        // two parts: 1. prefix sum of costs. 2. suffix sum of costs. 
        // During the iteration, record the minimum cost we have met.
        for (int i = 1; i < n; ++i) {
            int gap = numsAndCost[i][0] - numsAndCost[i - 1][0];
            totalCost += 1l * prefixCost[i - 1] * gap;
            totalCost -= 1l * (prefixCost[n - 1] - prefixCost[i - 1]) * gap;
            answer = min(answer, totalCost);
        }
        
        return answer;
    }
    // binary search
    long long minCost(vector<int>& A, vector<int>& cost) {
        long long l = 1, r = 1000000, res = f(A, cost, 1), x;
        while (l < r) {
            x = (l + r) / 2;
            long long y1 = f(A, cost, x), y2 = f(A, cost, x + 1);
            res = min(y1, y2);
            if (y1 < y2)
                r = x;
            else
                l = x + 1;
        }
        return res;
    }
​
    long long f(vector<int>& A, vector<int>& cost, int x) {
        long long res = 0;
        for (int i = 0; i < A.size(); ++i)
            res += 1L * abs(A[i] - x) * cost[i];
        return res;
    }
};
