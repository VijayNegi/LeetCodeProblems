class Solution {
public:
    vector<int> countBits(int n) {
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
};
