class Solution {
public:
    
    int gcd(int a,int b) {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    
    int mirrorReflection1(int p, int q) {
        int lcm = (p*q)/gcd(p, q); // calculating lcm using gcd
        int m = lcm/p;
        int n = lcm/q;
        if(n%2==0) return 2;
        if(m%2==0) return 0;
        return 1;
​
    }
    // https://leetcode.com/problems/mirror-reflection/discuss/2376191/C%2B%2B-Java-Python-or-Faster-then-100-or-Full-explanations-or
    // only odd even matters
    int mirrorReflection(int p, int q) {
        while (p % 2 == 0 && q % 2 == 0){ 
            p/=2;
            q/=2;
        }
        return 1 - p % 2 + q % 2;
    }
};
