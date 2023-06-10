class Solution {
public:
    int maxValue1(int n, int index, int maxSum) {
        maxSum-=n;
        int i=0;
        while(true){
            
            int l = max(index - i,0);
            int r = min(index + i,n-1);
            int s = r-l+1;
            //cout<<i<<" "<<s<<" "<<maxSum<<endl;
            if(maxSum<s )
                break;
            if(s==n){
                i += maxSum/s;
                maxSum %=s;
            }
            else{
                ++i;
                maxSum-=s;
            }
        }
        return i+1;
    }
    // Binary search
    // https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/discuss/1119801/JavaC%2B%2BPython-Binary-Search
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int left = 0, right = maxSum, mid;
        while (left < right) {
            mid = (left + right + 1) / 2;
            if (test(n, index, mid) <= maxSum)
                left = mid;
            else
                right = mid - 1;
        }
        return left + 1;
    }
​
    long test(int n, int index, int a) {
        int b = max(a - index, 0);
        long res = long(a + b) * (a - b + 1) / 2;
        b = max(a - ((n - 1) - index), 0);
        res += long(a + b) * (a - b + 1) / 2;
        return res - a;
    }
};
​
