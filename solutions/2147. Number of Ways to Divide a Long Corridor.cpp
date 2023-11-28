            int org = k;
            dp[org]=0;
            long long plant=0;
            while(k<n){
                if(corridor[k]=='S') ++count;
                else if(count==2 && corridor[k]=='P') ++plant;
                if(count == 3) dp[org] = (dp[org] + (dfs(k) * (plant+1) ))%mod;
                if(count>=3) break;
                ++k;
            }
            if(k==n && count==2)
                dp[org]=1;
            return dp[org];
        };
        
        return dfs(0);
    }
    // same as above but without dp
    int numberOfWays2(string s) {
        long res = 1, j = 0, k = 0, mod = 1e9 + 7;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'S') {
                if (++k > 2 && k % 2 == 1)
                    res = res * (i - j) % mod;
                j = i;
            }
        }
        return k % 2 == 0 && k > 0 ? res : 0;
    }
    // just dp optimization
    int numberOfWays(string corridor) {
        // Store 1000000007 in a variable for convenience
        const int MOD = 1e9 + 7;
​
        // Initial values of three variables
        int zero = 0;
        int one = 0;
        int two = 1;
​
        // Compute using derived equations
        for (char thing : corridor) {
            if (thing == 'S') {
                zero = one;
                swap(one, two);
            } else {
                two = (two + zero) % MOD;
            }
        }
​
        // Return the result
        return zero;
    }
};
