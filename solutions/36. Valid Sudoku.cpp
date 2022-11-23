class Solution {
public:
    // bitset : 62 ms
    bool isValidSudoku1(vector<vector<char>>& board) {
        vector<bitset<9>> rows(9),cols(9),boxes(9);
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.')
                    continue;
                int num = board[i][j]-'1';
                if(rows[i].test(num))
                    return false;
                rows[i].set(num);
                if(cols[j].test(num))
                    return false;
                cols[j].set(num);
                int b = (i/3)*3 + (j/3);
                if(boxes[b].test(num))
                    return false;
                boxes[b].set(num);
            }
        }
        return true;
    }
    //BitMasking : 41 ms
    bool isValidSudoku(vector<vector<char>>& board) {
        int cols[9] =  {0};
        int rows[9] = {0};
        int boxes[9] = {0};
        for(int i=0;i<9;++i)
        {
            for(int j=0 ; j<9 ; ++j )
            {
                if(board[i][j]=='.')
                    continue;
                int temp = 1 << (board[i][j]-'1');
                if(rows[i] & temp)
                    return false;
                rows[i] |=temp;
                if(cols[j] & temp)
                    return false;
                cols[j] |=temp;
                int bIdx =  ((i/3) * 3 ) + j/3;
                if(boxes[ bIdx] & temp)
                    return false;
                boxes[ bIdx] |= temp;
            }
            
        }
        return true;
    }
    // older solution
    bool isValidSudoku2(vector<vector<char>>& board) {
        
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
