class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j)
    {
        if(i<0 || j< 0)
            return;
        if(i>= board.size() || j>=board[0].size())
            return;
        if(board[i][j] == 'X' || visited[i][j])
            return;
        visited[i][j] = true;
        dfs(board,visited,i+1,j);
        dfs(board,visited,i,j+1);
        dfs(board,visited,i-1,j);
        dfs(board,visited,i,j-1);
        
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;++j)
            {
                if(i==0 || i == rows -1 || j== 0 || j == cols -1)
                    dfs(board,visited, i,j);
            }
        }
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;++j)
            {
                if(board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
        
    }
};
