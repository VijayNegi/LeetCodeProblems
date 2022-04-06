        unordered_map<int, long> c;
        for (int a : A) c[a]++;
        long res = 0;
        for (auto it : c)
            for (auto it2 : c) {
                int i = it.first, j = it2.first, k = target - i - j;
                if (!c.count(k)) continue;
                if (i == j && j == k)
                    res += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
                else if (i == j && j != k)
                    res += c[i] * (c[i] - 1) / 2 * c[k];
                else if (i < j && j < k)
                    res += c[i] * c[j] * c[k];
            }
        return res % int(1e9 + 7);
    }
    
    
    // 3 * i = target
    // 2 * i + j = target
    // i + 2 * j = target
    // i + j + k = target
    //https://leetcode.com/problems/3sum-with-multiplicity/discuss/181156/C%2B%2B-6-lines-4-ms-O(distinct(n)-2)
    // 10 ms
    int threeSumMulti(vector<int>& nums, int target) 
    {
        long m[101] = {}, res = 0;
        for (auto n : nums) ++m[n];
        for (auto i = 0; i < 101; ++i) {
            if (i * 3 == target) res += m[i] * (m[i] - 1) * (m[i] - 2) / 6;
            for (auto j = i + 1, k = target - i - j; j < 101; ++j, --k) {
                if (i * 2 + j == target) res += m[i] * m[j] * (m[i] - 1) / 2;
                if (i + j * 2 == target) res += m[i] * m[j] * (m[j] - 1) / 2;
                if (k > j && k < 101) res += m[i] * m[j] * m[k];
            }
        }
        return res % 1000000007;
    }
    
    
    
    
    // TLE
    int threeSumMulti1(vector<int>& arr, int target) {
        sort(begin(arr),end(arr));
        int n = arr.size();
        int result = 0;
        
        for(int i=0;i< n-2;++i)
        {
            for(int j=i+1;j<n-1;++j)
            {
                int s = target - arr[i] - arr[j];
                auto it = lower_bound(begin(arr)+j+1,end(arr),s);
                while(it!= arr.end() && *it==s)
                {
                    ++it,++result;
                }
