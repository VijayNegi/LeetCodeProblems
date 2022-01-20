class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long sum = 0;
        sum = accumulate(piles.begin(),piles.end(),sum);
        int avg = (sum + h -1)/h;
        
        int r = *max_element(piles.begin(),piles.end());
        int l = avg;
        
        while(l<r)
        {
            int mid = l + (r-l)/2;
            int hrs = 0;
            for(int a:piles)
                hrs += (a+mid-1)/mid;
            if(hrs>h)
                l = mid +1;
            else
                r = mid;
        }
        return l;
    }
};
