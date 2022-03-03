class Solution {
    vector<vector<int>> dp;
public:
    int numDupDigitsAtMostN(int n) {
        dp = vector(10,vector(1024,-1));
        int last = 0;
        string s = to_string(n);
        int len = s.size();
        bool flag = false; // if edge number are satisfy the condition
        int result=0;
        bool valid=false; // no leading zero for numbers with restriction.
        for(int i=0;i<len;++i)
        {
            int limit = s[i]-'0';
            for(int j=0;j<limit;++j)
            {
                int tvalid = valid || j >0;
                if((tvalid && isSet(last,j)) || flag)
                {
                    int dLeft = s.size()-i -1;
                    result += pow(10,dLeft);
                }
                else if(tvalid)
                {
                    int mask = setBit(last,j);
                    result+=digit_dp(s,i+1,mask,tvalid);
                }
                else
                    result+=digit_dp(s,i+1,0,tvalid);
            }
            if(isSet(last,limit))
                flag = true;
            valid = true;
            last = setBit(last,limit);
        }
        return result+flag;
    }
    int digit_dp(string s,int pos,int last,bool valid) // valid = valid number not starting with zero
    {
        if(pos==s.size())
            return 0;
        if(dp[pos][last]!=-1)
            return dp[pos][last];
        int sum=0;
        for(int i=0;i<10;++i)
        {
