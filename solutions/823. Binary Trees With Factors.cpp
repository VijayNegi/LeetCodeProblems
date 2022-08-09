const int mod = 1e9+7;
class Solution {
public:
    int numFactoredBinaryTrees1(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr),end(arr));
        unordered_map<int,long> memo;
        long result = 0;
        for(auto& k:arr) {
           memo[k] = 1;
        }
        for(int i=0;i<n;++i) {
            for(int j=0;j<=i;++j) {
                long mul = (long)arr[i]*arr[j];
                if(mul>=INT_MAX)
                    continue;
                if(memo.count(mul)) {
                    int count = (memo[arr[i]]*memo[arr[j]])%mod;
                    if(arr[i]!=arr[j])
                        count = (2l * count)%mod;
                    memo[mul] = (memo[mul] + count) %mod;
                }
            }
        }
        for(auto& c:memo){
            result += c.second;
            result %=mod;
        }
        return result;
    }
    // check overflow handle : 137 ms
    int numFactoredBinaryTrees(vector<int>& A) {
        long res = 0, mod = pow(10, 9) + 7;
        sort(A.begin(), A.end());
        unordered_map<int, long> dp;
        for (int i = 0; i < A.size(); ++i) {
            dp[A[i]] = 1;
            for (int j = 0; j < i; ++j)
                if (A[i] % A[j] == 0)
                    dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % mod;
            res = (res + dp[A[i]]) % mod;
        }
        return res;
    }
};
