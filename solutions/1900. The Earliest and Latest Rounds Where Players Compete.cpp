                    dfs(deadMask | (1<<i), i+1, j-1, curRound);
                if (j != first and j != second) // 'j' is MORTAL, he may die
                    dfs(deadMask | (1<<j), i+1, j-1, curRound);
​
            }
        };
        dfs(0,1,n,1);
        return {minRound, maxRound};
    }
    
    // 3ms with memoisation
    vector<int> earliestAndLatest2(int n, int first, int second) 
    {
        int min_r = INT_MAX, max_r = INT_MIN;
        bool visited[27][27][27] = {};
        --first;
        --second;
        
        function<void(int,int,int,int,int,int,int)> dfs = [&](int mask, int round, int i, int j, int l, int m, int r) 
        {
            if (i >= j)
                dfs(mask, round + 1, 0, 27, l, m, r);
            else if ((mask & (1 << i)) == 0)
                dfs(mask, round, i + 1, j, l, m, r);
            else if ((mask & (1 << j)) == 0)
                dfs(mask, round, i, j - 1, l, m, r);
            else if (i == first && j == second) {
                min_r = min(min_r, round);
                max_r = max(max_r, round);
            }
            else if (!visited[l][m][r]) {
                visited[l][m][r] = true;
                if (i != first && i != second)
                    dfs(mask ^ (1 << i), round, i + 1, j - 1, 
                        l - (i < first), m - (i > first && i < second), r - (i > second));
                if (j != first && j != second)
                    dfs(mask ^ (1 << j), round, i + 1, j - 1,
                        l - (j < first), m - (j > first && j < second), r - (j > second));
            }
        };
        
        dfs((1 << n) - 1, 1, 0, 27, first, second - first -1, n - second);
        return { min_r, max_r };
    }
    
    
    // 0 ms
    vector<int> earliestAndLatest(int n, int first, int second) 
    {
        int min_r = INT_MAX, max_r = INT_MIN;
        function<void(int,int,int,int)> dfs = [&](int l, int r, int n, int round) 
        {
            if (l == r) {
                min_r = min(min_r, round);
                max_r = max(max_r, round);
            }
            else
                if (l > r)
                    swap(l, r);
                for (int i = 1; i < l + 1; ++i)
                    for (int j = l - i + 1; i + j <= min(r, (n + 1) / 2); ++j)
                        if (l + r - (i + j) <= n / 2)
                            dfs(i, j, (n + 1) / 2, round + 1);
        };
        
        dfs(first, n - second + 1, n, 1);
        return { min_r, max_r };
    }
};
