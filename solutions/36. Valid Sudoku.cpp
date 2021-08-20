class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //vector<vector<int>> m(9,vector<int>(9,0));
        
        for(int i=0;i<9;++i)
        {
            int m[9] = {0};
            for(int j=0;j<9;++j)
            {
                if(board[i][j]=='.') continue;
                if(m[board[i][j]-'1'])
                    return false;
                m[board[i][j]-'1'] = 1;
            }
        }
        for(int i=0;i<9;++i)
        {
            int m[9] = {0};
            for(int j=0;j<9;++j)
            {
                if(board[j][i]=='.') continue;
                if(m[board[j][i]-'1'])
                    return false;
                m[board[j][i]-'1'] = 1;
            }
        }
        
        for(int r=0;r<3;++r)
        {
            for(int c=0;c<3;++c)
            {
                 int m[9] = {0};
                for(int i=0;i<3;++i)
                {
                    for(int j=0;j<3;++j)
                    {
                        if(board[r*3 +i][c*3+j]=='.') continue;
                        if(m[board[r*3 +i][c*3+j]-'1'])
                            return false;
                        m[board[r*3 +i][c*3+j]-'1'] = 1;
                    }
                }
            }
        }
        
        for(int i=0;i<9;++i)
        {
            int m[9] = {0};
            for(int j=0;j<9;++j)
            {
                if(board[j][i]=='.') continue;
                if(m[board[j][i]-'1'])
                    return false;
                m[board[j][i]-'1'] = 1;
            }
        }
        
        return true;
    }
};
