class Solution {
public:
    // 17ms
    int totalNQueens1(int n) {
        int result=0;
        vector<string> board(n,string(n,'.'));
        function<bool(int,int)> valid = [&]( int l,int i) {
            // check down
            for(int k=l-1;k>=0;--k)
                if(board[k][i]=='Q') 
                    return false;
            //check down right
            for(int k=l-1,c=i+1;k>=0 && c<n;--k,++c)
                if(board[k][c]=='Q') 
                    return false;
            // check down left
            for(int k=l-1,c=i-1;k>=0 && c>=0;--k,--c)
                if(board[k][c]=='Q') 
                    return false;
            return true;
        };
        function<void(int)> dfs = [&](int l) {
            if(l==n) {
                ++result;
                return;
            }
​
            for(int i=0;i<n;++i) {
                if(!valid(l,i))
                    continue;
                board[l][i]='Q';
                dfs(l+1);
                board[l][i]='.';
            }   
        };
        
        dfs(0);
        return result;
    }
    // valid check optimized : 3 ms
    int totalNQueens(int n) {
        int result=0;
        vector<int> cols(n,0);
        vector<int> ldiag(2*n,0);
        vector<int> rdiag(2*n,0);
​
