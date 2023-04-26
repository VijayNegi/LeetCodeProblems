class Solution {
public:
    int addDigits1(int num) {
        string s = to_string(num);
        while(s.size()!=1){
            int n=0;
            for(auto& k:s){
                n += k-'0';
            }
            s = to_string(n);
        }
        return s[0]-'0';
    }
    int addDigits2(int num) {
        
        int res=0;
        while(num)
        {
            res += num%10;
            num /=10;
            if(num==0 && res > 9)
            {
                num = res;
                res=0;
            }
        }
        return res;
    }
     int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};
