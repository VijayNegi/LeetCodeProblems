class Solution {
public:
    int numTrees(int n) {
        
        vector<int> mem(n+3,0);
        mem[0] = 1;
        mem[1] = 1;
        mem[2] = 2;
        function<int(int,int)> uniqueBST = [&](int start,int end)
        {
            
            int s = end - start +1;
            if(mem[s]>0)
                return mem[s];
            
            int ways=0;
            for(int i=start;i<=end; ++i)
            {
                int left = uniqueBST(start,i-1);
                int right = uniqueBST(i+1,end);
                ways += left * right;
            }
            mem[s] = ways;
            return ways;
        };
        
        return uniqueBST(1,n);
        
    }
};
