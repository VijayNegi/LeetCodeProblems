class Solution {
    vector<int> mem;
public:
    Solution():mem(31,0) {
    }
    // recursion
    int fib1(int n) {
        if(n<2)
            return n;
        if(mem[n]!=0)
            return mem[n];
        return mem[n] = fib(n-1)+fib(n-2);
    }
    // iteration
    int fib2(int n) {
        std::vector<int> dp(n+2,-1);
        dp[0]=0;
        dp[1]=1;
        int i=1;
        while(++i<=n) {
            dp[i]=dp[i-2]+dp[i-1];
        }
        return dp[n];
    }
    // iterative, space optimised 
    int fib(int N) {
        if(N < 2) 
            return N;
        int a = 0, b = 1, c = 0;
        for(int i = 1; i < N; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
    
    // fast doubling
    pair<int, int> fib_helper (int n) {
        if (n == 0)
            return {0, 1};
        auto p = fib_helper(n >> 1);
        int c = p.first * (2 * p.second - p.first);
        int d = p.first * p.first + p.second * p.second;
        if (n & 1)
            return {d, c + d};
        else
            return {c, d};
    }
    int fib3(int n) {
        auto res = fib_helper(n);
        return res.first;
    }
​
};
