class Solution {
public:
    //BitMasking
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
    bool isValidSudoku1(vector<vector<char>>& board) {
        
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
