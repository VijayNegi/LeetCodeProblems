const int mod = 1e9+7;
#define ll long long
class Solution {
public:
    // self : TLE
    int countPalindromes1(string s) {
        vector<vector<int>> stk(10);
        int n = s.size();
        for(int i=0;i<s.size();++i){
            stk[s[i]-'0'].push_back(i);
        }
        int result = 0;
        for(int i=0;i<n-4;++i){
            for(int j=i+1;j<n-3;++j){
                int fir = s[i]-'0';
                int sec = s[j]-'0';
                int r  = stk[fir].size()-1;

                for(;r>=0 && stk[fir][r]>j+1;--r){
                    int rr = stk[sec].size()-1;
                    while(rr>=0 && stk[sec][rr] >= stk[fir][r]) --rr;
                    for(;stk[sec][rr]>j+1;--rr){
                        result += (stk[sec][rr]-j)-1;
                        result %=mod;
                    }
                }
            }
        }
        return result;
    }
    // o(1) space, from one contestent
    // 828 ms
    int countPalindromes2(string s) {
			int n = s.size();
			long ans = 0;
			int ff[10] = {0};
			for(int i = 0;i < n;i++){
				long m = 0;
				for(int j = n-1;j > i;j--){
					if(s[i] == s[j]){
						ans += m * (j-i-1);
					}
					m += ff[s[j]-'0'];
					if(m >= mod)m -= mod;
				}
				ff[s[i] - '0']++;
			}
			return (int)(ans % mod);
	}
    
    ll dp[10001][11][11][6];
    ll dfs(int ind, int first, int second, int i, string &s) {
        if(i == 5) return 1; //found a subsequence
        if(ind == s.length()) return 0;
        if(dp[ind][first][second][i] != -1) return dp[ind][first][second][i];
        
        //option of not choosing current digit
        long long res = dfs(ind + 1, first, second, i, s);

        if(i == 0) {
            //option of choosing the first digit of the subsequence
            res += dfs(ind + 1, s[ind] - '0', second, i + 1, s);
            res %= mod;
        } else if(i == 1) {
            //option of choosing the second digit of the subsequence
            res += dfs(ind + 1, first, s[ind] - '0', i + 1, s);
            res %= mod;
        } else if(i == 2) {
            //option of choosing the third digit of the subsequence
            res += dfs(ind + 1, first, second, i + 1, s);
            res %= mod;
        } else if(i == 3) {
            //option of choosing the fourth digit of the subsequence if it matches with the second digit
            if(s[ind] - '0' == second) {
                res += dfs(ind + 1, first, second, i + 1, s);
                res %= mod;
            }
        } else if(i == 4) {
            //option of choosing the fifth digit of the subsequence if it matches with the first digit
            if(s[ind] - '0' == first) {
                res += dfs(ind + 1, first, second, i + 1, s);
                res %= mod;
            }
        }
        return dp[ind][first][second][i] = res;
    }
    //https://leetcode.com/problems/count-palindromic-subsequences/discuss/2850433/4D-DP-oror-C%2B%2B-oror-Top-Down
    // 4D DP: 1270 ms
    int countPalindromes(string s) {
        memset(dp, -1, sizeof dp); 
        return dfs(0, 10, 10, 0, s);
    }
};
