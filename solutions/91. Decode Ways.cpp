class Solution {
public:
    int numDecodings1(string s) {
        vector<int> mem(s.size()+1,-1);
        return dfs(s,0,mem);
    }
    
    int dfs(string s, int idx,vector<int>& mem)
    {
        if(idx==s.size()) return 1;
        if(s[idx] == '0') return 0;
        if(idx==s.size()-1) return 1;
​
        if(mem[idx]>=0)
            return mem[idx];
            
        int ways = 0;
        ways+= dfs(s,idx+1,mem);
        
        if(s[idx]=='1')
            ways+= dfs(s,idx+2,mem);
        else if(s[idx]=='2')
        {
            if(s[idx+1]<='6')
                ways+= dfs(s,idx+2,mem);
        }
        mem[idx] = ways;
        return ways;
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
