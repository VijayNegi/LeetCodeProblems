class Solution {
public:
    //bruteforce
    int arrangeCoins1(int n) {
        int count=0;
        int coin = n;
        for(count=1;count<=n && count<=coin ;++count)
            coin-=count;
​
        return --count;
    }
    // binary search
    int arrangeCoins2(int n) {
        int count=-1;
        
        long left=0;
        long right = (n+1.f)/2;
        
        while(left<=right)
        {
            long mid = left + (right-left)/2;
            long sum = (mid*(mid+1))/2;
            if( sum == n)
            {
                count = mid;
                break;
            }
            else if(sum < n)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        
        if(count ==-1)
            count = --left;
    
        return count;
    }
    // formula
    int arrangeCoins(int n) {
        int count=0;
        long coin = n;
       
        count = sqrt(2*coin + .25) - 0.5;
        return count;
    }
};
