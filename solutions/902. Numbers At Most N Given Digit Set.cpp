class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        int t = n;
        vector<int> num;
        while(t>0)
        {
            num.push_back(t%10);
            t/=10;
        }
    
        int p = num.size();
        int d = digits.size();
        vector<int> di(d,0);
        for(int i=0;i<d;++i)
        {
            di[i] = digits[i][0] - '0';
        }
        
        function<int(int)> countless = [&](int k){
            auto it = upper_bound(di.begin(),di.end(),k);
            return distance(di.begin(),it);
        };
        
        int res = 0;
        
        for(int i=1;i!= p;++i)
            res+= pow(d,i);
     
        for(int i=p-1;i>=0;--i)
        {
            int k = countless(num[i]); // digits less then current digit of n
            if(k==0)
                break;
            
            if(di[k-1] < num[i])
            {
                res += k * pow(d,i);
                return res;
            }
            else
            {
                res += (k-1) * pow(d,i);
                if(i==0)
                    ++res;
            }
                
                
        }
        
        return res;
    }
};
