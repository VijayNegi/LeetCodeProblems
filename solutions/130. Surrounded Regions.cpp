class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        
        static const function<void(int,int)> markBorder = [&](int i,int j)
            {
                if(i<0 || i>=rows || j<0 || j>=cols || board[i][j] !='O')
                    return;
                board[i][j] = 'B';
                markBorder(i+1,j);
                markBorder(i,j+1);
                markBorder(i-1,j);
                markBorder(i,j-1);
            };
        
        for(int j=0;j<cols;++j)
        {
            markBorder(0,j);
            markBorder(rows-1,j);
        }
        
        for(int i=0;i<rows;++i)
        {
            markBorder(i,0);
            markBorder(i,cols-1);
        }
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;++j)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j]== 'B')
                    board[i][j] = 'O';
            }
        }
        
    }
};
