class Solution {
public:
    // mine as input parameters are not big
    int getSum1(int a, int b) {
        int min = (abs(a)>abs(b))?b:a;
        int max =  (abs(a)>abs(b))?a:b;
        bool op = min>=0? true:false;
        for(int i=0;i<abs(min);++i)
        {
            if(op)
                ++max;
            else
                --max;
        }
        return max;
    }
    // bitwise as recursion - https://leetcode.com/problems/sum-of-two-integers/discuss/84277/One-liner-with-detailed-explanation
    int getSum2(int a, int b) {
        if(b == 0) return a;
        int carry = (unsigned int) (a & b) << 1; // avoid left shifting negative values
        int sum = a ^ b;
        return getSum(sum, carry);
    }
    
    // bitwise as iteration
    int getSum(int a, int b) {
        int sum = a;
        
        while (b != 0)
        {
            sum = a ^ b;        //calculate sum of a and b without thinking the carry 
            b = (unsigned int) (a & b) << 1;   //calculate the carry
            a = sum;            //add sum(without carry) and carry
        }
        
        return sum;
    }
    
};
