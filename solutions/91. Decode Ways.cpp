class Solution {
public:
    int numDecodings1(string s) {
        int result=0;
        int n = s.size();
        vector<int> memo(n,-1);
        function<int(string&,int)> dfs = [&](string& str,int pos) {
            if(pos>=n)          return 1;
            if(memo[pos] != -1) return memo[pos];
            if(str[pos] == '0') return 0;
            memo[pos] = dfs(str,pos+1);
            if( pos < n-1 && ( str[pos] =='1' || (str[pos]=='2' && str[pos+1]<'7')))
                memo[pos] += dfs(str,pos+2);
            return memo[pos];
        };
        return dfs(s,0);
    }
       //https://leetcode.com/problems/decode-ways/discuss/30451/Evolve-from-recursion-to-dp
    // dp with constant memory
    int numDecodings(string s) {
        int p = 1, pp, n = s.size();
        for(int i=n-1;i>=0;i--) {
            int cur = s[i]=='0' ? 0 : p;
            if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) cur+=pp;
            pp = p;
            p = cur;
        }
        return s.empty()? 0 : p;   
    }
};
