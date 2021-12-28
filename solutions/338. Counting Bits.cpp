class Solution {
public:
    // self : 4ms
    vector<int> countBits1(int n) {
        vector<int> res(n+1,0);
        if(n==0)
            return res;
        res[1] = 1;
        
        int low = 2;
        int high = 1<<2;
            
        int i=0;
        while(low<=n)
        {
            res[low] = res[i] +1;
            ++low;
            ++i;
            if(low == high)
            {
                high = high << 1;
                i=0;
            }
        }
        return res;
    }
    // shifting by one to right(multiply by 2) doesnt increase bit count. shiftring to left(divide by 2) will only decrease bit count by one if no is odd.
    vector<int> countBits2(int n) {
         
        vector<int> res(n+1,0);
        for (int i=1; i<=n; i++) 
            res[i] = res[i >> 1] + (i & 1);
        return res;
    }
    // i&(i-1) will remove lowest set bit, so we have already removed one bit , so just add one bit count with that number.
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
    
};
