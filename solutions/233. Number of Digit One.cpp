            int lmt = edge && i==limit;
            if(i==1)
            {
                result += digit_dp(s,pos+1,sum+1, lmt);
            }
            else
                result += digit_dp(s,pos+1,sum, lmt);
        }
        return dp[pos][sum][edge] = result;
    }
    //digit dp 2 states: 0 ms
    // notes , Sum keeps track of numbers in the bondry of each digit. at end it will be of limit number
     int countDigitOne2(int n) {
        dp2 = vector(10,vector(82,-1));
        string s = to_string(n);
         int len = s.size();
         int sum = 0;
         int result = 0;
         for(int i=0;i<len;++i)
         {
             int limit = s[i]-'0';
             for(int j=0;j<limit;++j)
             {
                 result += digit_dp2(s,i+1,sum + (j==1));
             }
             if(limit==1)
                 ++sum;
         }
        return result + sum;
    }
    
    int digit_dp2(string s,int pos,int sum)
    {
        if(pos == s.size())
            return sum;
        if(dp2[pos][sum] != -1)
            return dp2[pos][sum];
        int limit = 9;
        int result = 0;
        for(int i=0;i<=limit;++i)
        {
            result += digit_dp2(s,pos+1,sum+(i==1));
        }
        return dp2[pos][sum] = result;
    }
    
    // maths solution
    int countDigitOne(int n) {
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10)
            ones += (n/m + 8) / 10 * m + (n/m % 10 == 1) * (n%m + 1);
        return ones;
    }   
};
