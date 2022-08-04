class Solution {
public:
    
    int gcd(int a,int b) {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    
    int mirrorReflection(int p, int q) {
        int lcm = (p*q)/gcd(p, q); // calculating lcm using gcd
        int m = lcm/p;
        int n = lcm/q;
        if(n%2==0) return 2;
        if(m%2==0) return 0;
        return 1;
​
    }
};
