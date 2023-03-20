class Solution {
public:
    bool canPlaceFlowers1(vector<int>& fbed, int n) {
        int k = fbed.size();
        int result=0;
        for(int i=0;i<k;i++){
            if(!fbed[i]){
                if(i>0 && fbed[i-1]) continue;
                if(i<k-1 && fbed[i+1]) continue;
                fbed[i]++;
                ++result;
            }
        }
        return result>=n;
    }
    // older solution
    // calculate empty streach and then find how many plants we can fit in that streach
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
