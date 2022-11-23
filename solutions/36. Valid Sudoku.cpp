class Solution {
public:
    // bitset : 62 ms
    bool isValidSudoku1(vector<vector<char>>& board) {↔}
    //BitMasking : 41 ms
    bool isValidSudoku(vector<vector<char>>& board) {↔}
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
