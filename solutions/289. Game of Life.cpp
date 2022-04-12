class Solution {
public:
     // Space O(1)
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> dir{{-1,-1},{-1,0},{-1,+1}, 
                                {0,-1},{0,+1},
                                {1,-1},{1,0},{1,+1}};
        for(int i=0;i < rows;++i)
            for(int j=0;j<cols;++j)
            {
                int neighbours = 0;
                for(auto& n:dir)
                {
                    int r = i+n[0],c = j+n[1];
                    if(r>=0 && r<rows && c>=0 && c<cols)
                        neighbours += board[r][c] & 1;
                }
                if(neighbours == 2)
                    board[i][j] |= board[i][j]<<1;
                else if(neighbours== 3)
                    board[i][j] |= 2;
            }
        for(int i=0;i<rows;++i)
            for(int j=0;j<cols;++j)
                board[i][j] = board[i][j]>>1;
        
    }
    // Space: O(n)
    void gameOfLife1(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> count(rows,vector(cols,0));
        for(int i=0;i<rows;++i)
            for(int j=0;j<cols;++j)
            {
                if(i<rows-1)
                {
                    count[i][j] += board[i+1][j];
                    count[i+1][j] += board[i][j];
                    if(j>0)
                    {
                        count[i][j] += board[i+1][j-1];
                        count[i+1][j-1] += board[i][j];
                    }
                }
                if(j<cols-1)
                {
                    count[i][j] += board[i][j+1];
                    count[i][j+1] += board[i][j];
                }
                if(j<(cols-1) && i<(rows-1))
                {
                    count[i][j] += board[i+1][j+1];
                    count[i+1][j+1] += board[i][j];
                }
                
            }
        for(int i=0;i<rows;++i)
            for(int j=0;j<cols;++j)
            {
                if(count[i][j]<2)
                    board[i][j]=0;
                else if(count[i][j]==3)
                    board[i][j]=1;
                else if(count[i][j]>3)
                    board[i][j]=0;
            }
    }
   
};
