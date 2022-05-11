class Solution {
public:
    // dp
    int countVowelStrings1(int n) {
        int k=5;
        int result=1;
        vector<vector<int>> dp(n+1,vector(k+1,0));
        function<int(int,int)> dfs = [&](int v,int pos){
            if(pos==0)
                return 1;
            if(dp[pos][v]!=0)
                return dp[pos][v];
            int result = 0;
            for(int i=1;i<=v;++i)
                result += dfs(i,pos-1);
            return dp[pos][v] = result;
        };
        result = dfs(k,n);
        return result;
    }
    // combination version
    int countVowelStrings2(int n) {
//                a  e  i  o  u
//     initialy: {1, 1, 1, 1, 1}   
//      n == 1 : {5, 4, 3, 2, 1}   
//      n == 2 : {15,10,6, 3, 1}   
//      n == 3 : {35,20,10,4, 1}   
//      
        int k=4;
        int permutation[] = {1,1,1,1,1};
        
        for(int i = 0 ;i < n; i++)
            for(int j = k-1; j>=0; j--)
                permutation[j] += permutation[j+1] ;
           
        return permutation[0];
    }
    
    // math
    int countVowelStrings(int n) {
        return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
    }
};
