typedef long long ll;
class Solution {
public:
    // contest : n^2
    long long subArrayRanges1(vector<int>& nums) {
      
        int n = nums.size();
        ll rangeSum = 0;
        int l=0;
        int h=0;
        for(int i=0;i<n;++i)
        {
            l = nums[i];
            h = nums[i];
            for(int j=i+1;j<n;++j)
            {
                l = min(l,nums[j]);
                h = max(h,nums[j]);
                rangeSum += (h-l);
            }
        }
        return rangeSum;
    }
    // monotonic stack : 12 ms
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        function<ll(function<bool(int,int)>)> subArraySum = [&](function<bool(int,int)> comp)
        {
            vector<int> s;
            ll res=0;
            for(int i=0;i<=n;++i)
            {
                while(!s.empty() && (i==n || comp(nums[s.back()],nums[i])))
                {
                    int k = s.back();
                    s.pop_back();
                    int j = s.empty()? -1 : s.back();
                    res += (ll)nums[k]*(k-j)*(i-k) ;
                }
                s.push_back(i);
            }
            return res;
        };
        
        ll mi = subArraySum(greater<int>{});
        ll ma = subArraySum(less<int>{});
        return ma- mi;
    }
};
