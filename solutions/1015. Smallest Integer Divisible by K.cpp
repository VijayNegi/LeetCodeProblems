class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0)
            return -1;
        
        int len = 0;
        unsigned long long n = 0;
     
        while(len < k+1 )
        {
            n = n*10+1;
            ++len;
​
            if(n % k == 0)
                return len;
             n = n%k;
        }
       
        return -1;
    }   
};
