class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ptwo=0;
        int value=0;
        int diff = n-m; 
        
        while(m!=n){
            m = m>>1;
            n = n>>1;
            ptwo++;
        }
        return n<<ptwo;
        // for (size_t i = 0; i < 31; i++)
        // {
        //     if(ptwo<m){
        //         if(ptwo>diff)
        //             value|=ptwo;
        //     }
        //     // else if(ptwo<=n )
        //     //      value&=ptwo;
        //     else 
        //         break;
            
        //     ptwo = ptwo<<1;
        // }
        // return n & m & value;
        
    }
};
