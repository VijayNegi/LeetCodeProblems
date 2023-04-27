class Solution {
public:
    int bulbSwitch1(int n) {
        long k=1;
        while(n>=k*k){
            k++;
        }
        return k-1;
    }
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
