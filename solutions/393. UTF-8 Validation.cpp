class Solution {
public:
    //self
    bool validUtf8_1(vector<int>& data) {
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
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (auto c : data) {
            if (count == 0) {
                if ((c >> 5) == 0b110) count = 1;
                else if ((c >> 4) == 0b1110) count = 2;
                else if ((c >> 3) == 0b11110) count = 3;
                else if ((c >> 7)) return false;
            } else {
                if ((c >> 6) != 0b10) return false;
                count--;
            }
        }
        return count == 0;
    }
};
