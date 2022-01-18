class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int fn = flowerbed.size();
        int emp = 0;
        for(int i=0;i<fn;++i)
        {
            if(flowerbed[i])
            {
                count += emp/2;
                emp = -1;
            }
            else
                ++emp;
        }
        count += (emp+1)/2;
        return count>=n;
        
    }
};
