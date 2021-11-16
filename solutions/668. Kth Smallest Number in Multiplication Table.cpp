class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        
        function<bool(int)> count = [m,n,k](int x)
        {
            int ans(0);
            for(int i=1;i<=m;++i)
            {
                ans += min(x/i,n);
            }
            return ans < k;
        };
     
        int res(0);
        int hi = m*n;
        int low = 1;
        
        while(hi>=low)
        {
            int mid = low + (hi - low)/2;
​
            if(count(mid))
                low = mid+1;
            else
            {
                hi = mid - 1;
                 res = mid;
            }
        }
        
        return res;
    }
};
