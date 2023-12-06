class Solution {
public:
    int totalMoney1(int n) {
        int res=0;
        int week=4;
        while(n){
            if(n>=7){
                n-=7;
                res += week*7;
                ++week;
            }
            else{
                --n;
                res += week -3;
                ++week;
            }
        }
        return res;
    }
    //O(1)
    int totalMoney(int n) {
        int k = n / 7;
        int F = 28;
        int L = 28 + (k - 1) * 7;
        int arithmeticSum = k * (F + L) / 2;
        
        int monday = 1 + k;
        int finalWeek = 0;
        for (int day = 0; day < n % 7; day++) {
            finalWeek += monday + day;
        }
        
        return arithmeticSum + finalWeek;
    }
};
