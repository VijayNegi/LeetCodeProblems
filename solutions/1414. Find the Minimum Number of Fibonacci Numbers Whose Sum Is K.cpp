typedef long long ll;
class Solution {
public:
    // return n, n+1
    pair<int, int> fib (int n) 
    {
        if (n == 0)
            return {0, 1};
​
        auto p = fib(n >> 1);
        int c = p.first * (2 * p.second - p.first);
        int d = p.first * p.first + p.second * p.second;
        if (n & 1)
            return {d, c + d};
        else
            return {c, d};
    }
    
    int findMinFibonacciNumbers(int k) {
        
        // fast doubling method
        ll a=0,b=1;
        ll n = 1;
        while(b < k)
        {
            
            ll a1 = a * (2* b - a);
            ll b1 = a*a + b*b;
            if(n & 1)
            {
                a = b1; 
                b = a1 + b1;
            }
            else
            {
                a = a1;
                b = b1;
            }
            n = n << 1;
        }
        ll ans = 0;
        while(k)
        {
            while(b <= k) // remove max no of b
            {
                k -=b;
                ++ans;
            }
            
            ll temp = a;
            a = b - a;
            b = temp;
        }
        return ans;
    }
};
