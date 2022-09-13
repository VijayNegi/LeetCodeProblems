class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int dbytes = 1<<7;
        int mask = 1<<7 | 1<<6;
        int i=0;
        while(i<n) {
            int k = 0;
            int p = data[i++];
            for(int j=7;j>0;--j) // could have used bitset
                if(p & (1<<j) )
                    ++k;
                else break;
            if(k>4 || k==1) return false;
            if((i+k-2)>=n && k>0)
                return false;
            for(int j=1;j<k;++j) {
                int m = data[i++] & mask;
                if(m != dbytes)
                    return false;
            }
        }
        return true;
    }
};
