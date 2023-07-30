class Solution {
public:
    // self : fail on "abggbacddca"
    // This will not work because below algorithm will fails to segment curr str based on curr char which will be prev for segments inside.
    // It will so once one prev replaces previous prev , previous prev wont be back.
    // i.e. prev kind of need to be in stack
    int strangePrinter1(string s) {
        int n = s.size();

        vector<vector<vector<int>>> dp(n,vector(n,vector(27,-1)));
        function<int(int,int,char)> print = [&](int l,int r,char prev){
            if(l>r) return 0;
            if(dp[l][r][prev-'a'] != -1) return dp[l][r][prev-'a'];
            // skip prev from both left and right
            while(r>=l && s[r] == prev) --r;
            while(l<=r && s[l] == prev) ++l;
            if(l>=r) return 0;
            int k = l;
            int j = r;
            // skip initial char from both left and right
            while(k<=r && s[l] == s[k])
                ++k;
            while(j>=k && s[l] == s[j])
                --j;
            int result = 0;
            if(k<=r)
                result = min(print(k,r,prev), print(k,j,s[l]));
            ++result;
            //cout<<l<<" "<<r<<" "<<prev<<"= "<<result<<endl;
            return dp[l][r][prev-'a'] = result;
        };
        
        return print(0,n-1, 'z'+1);
    }
    // top down :
    int strangePrinter2(std::string s)
    {   
        int n = s.size();
        vector<vector<int>> dp(n,vector(n,0));
        
        function<int(int,int)> dfs = [&]( int l, int r)
        {
            if (l > r) return 0;
            if (dp[l][r]) return dp[l][r];
            dp[l][r] = dfs(l, r - 1) + 1;
            for (int i = l; i < r; ++i)
            {
                if (s[i] == s[r])
                {
                    // why below code works ?
                    // assume count to print from l to i, for i char we printed it till r. 
                    // so cost of printing char i is already covered.
                    // so we only need to add count of i+1 to r-1
                    dp[l][r] = std::min(dp[l][r], dfs(l, i) + dfs(i + 1, r - 1));
                }
            }
            return dp[l][r];
        };

        return dfs( 0, n - 1);
    }
    // bottom up and make it symatric
    int strangePrinter(string s) {
        int n = s.size();
        string p{s[0]};
        for(int i=1;i<n;++i)
            if(s[i]!=s[i-1])
                p.push_back(s[i]);
        s= p;
        n = s.size();
        vector<vector<int>> dp(n,vector(n,0));
        for(int i=0;i<n;++i)
            dp[i][i] = 1;
         
         for(int len=1;len<=n;++len)
         {
             for(int start = 0;start < n-len;++start)
             {
                 int end = start + len;
                 dp[start][end] = len +1;
                 for(int k=start;k<end;++k)
                 {
                     int sub = (s[k] == s[end])?1:0;
                      dp[start][end]= min(dp[start][end],dp[start][k]+ dp[k+1][end] - sub);
                 }
             }
         }
        
        return dp[0][n-1];
    }
    
};
// very good code with explanations
/*
class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    // Helper function to find the minimum number of operations required to print substring s[i...j]
    int f(int i, int j, string& s){       
        // If dp[i][j] has already been calculated, return its value to avoid recomputation.
        if (dp[i][j]!=-1) return dp[i][j];
        
        // initial case: When i=j, it only takes 1 operation to print it.
        if (i==j) return dp[i][j]=1;
        
        int ans; // Variable to store the minimum number of operations required to print substring s[i...j].
        
        // If s[i]==s[j] or s[j]==s[j-1],
        // then it's equivalent to printing substring s[i...j-1].
        if (s[i]==s[j]||s[j-1]==s[j]) ans=f(i, j-1, s);
        
        // If s[i]==s[i+1], it's equivalent to printing substring s[i+1...j].
        else if (s[i]==s[i+1]) ans=f(i+1, j, s);
        
        // If the above two conditions are not met, it means that s[i] and s[j] are different, and s[j] is also different 
        // from the character before it. In this case, we have multiple options:
        else{
            // Option 1: Print s[i...j-1] and then the character at position j, so the number of operations is f(i,j-1,s) + 1.
            ans=f(i,j-1, s)+1;
            
            // Option 2: We can try to find a character k between i and j (exclusive) such that s[k] is the same as s[j].
            // If we find such a character, it means we can print s[i...k-1] and s[k...j-1] together as one operation,
            // since both sequences will end with the same character s[j]. The number of operations would be f(i,k-1,s) + f(k,j-1,s).
            // We try all possible k values and choose the minimum among them.
            for(int k=i+1; k<j; k++){
                if(s[k]==s[j])
                    ans=min(ans, f(i, k-1, s)+f(k, j-1, s));
            }
        }
        // Save the computed result in dp table to avoid recomputation for the same subproblems.
        return dp[i][j]=ans;
    }
    
    int strangePrinter(string s) {
        n=s.size(); // Get the size of the input string.
        dp.assign(n, vector<int>(n, -1)); // Initialize the dp table with -1 to mark that no subproblem has been computed yet.
        return f(0, n-1, s); // Call the helper function to find the minimum number of operations to print the entire string.
    }
};
*/
