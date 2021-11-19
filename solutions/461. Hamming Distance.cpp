class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y;
        int ans(0);
        for(int i=0; i!=32 && z ; ++i)
        {
            ans += z & 1;
            z = z>>1;
        }
        return ans;
        
    }
};
