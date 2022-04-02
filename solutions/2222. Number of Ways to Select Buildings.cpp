class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.size();
        vector<long> zero(n+2,0);
        vector<long> one(n+2,0);
        for(int i=0;i<n;++i)
        {
            if(s[i]=='0')
                zero[i] = 1;
            else
                one[i] = 1;
            zero[i] += i>0? zero[i-1]:0;
            one[i] += i>0? one[i-1]:0;
        }
        long long result=0;
        long left,right;
        for(int i=1;i<n-1;++i)
        {
            // select center
            if(s[i]=='0')
            {
                left = one[i];
                right = one[n-1] - left;
                result += left*right;
            }
            else
            {
                left = zero[i];
                right = zero[n-1] - left;
                result += left*right;
            }
        }
        return result;
    }
};
