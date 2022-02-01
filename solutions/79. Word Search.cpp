class Solution {
public:
    // 400 ms
    bool exist1(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        int dirx[4] = {1,0,-1,0};
        int diry[4] = {0,1,0,-1};
        function<bool(int,int,int)> dfs = [&](int r,int c,int idx)
        {
            char ch = board[r][c];
            if(ch =='#' || ch!=word[idx])
                return false;
            if(idx== word.size()-1)
                return true;
            board[r][c] = '#';
            for(int dir=0;dir < 4;++dir)
            {
                int rr,cc;
                rr = r+dirx[dir];
                cc = c+diry[dir];
                
                if(rr<0 || rr>= rows) continue;
                if(cc<0 || cc>= cols) continue;
                if(dfs(rr,cc,idx+1))
                    return true;
            }
            board[r][c] = ch;
            return false;
        };
        for(int r = 0;r<rows;++r)
        {
            for(int c = 0;c<cols;++c)
            {
                if(board[r][c] == word[0] && dfs(r,c,0))
                    return true;
            }
        }
        return false;
    }
    // Backtracking implmentation , 192 ms
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(adjacentSearch(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    
    }
protected:
    bool adjacentSearch(vector<vector<char>>& board, const string& word, int i, int j, int index)
    {
        if(index == word.size()) return true; // end condition
        if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1) return false; // boundary of matrix
        if(board[i][j] != word[index]) return false; // do not match
        // match!
        board[i][j] = '*'; // change the content, to avoid duplicated search
        bool furtherSearch =  adjacentSearch(board, word, i+1, j, index+1) || // up
                              adjacentSearch(board, word, i-1, j, index+1) || // down
                              adjacentSearch(board, word, i, j-1, index+1) || // left
                              adjacentSearch(board, word, i, j+1, index+1);   // right
        
        board[i][j] = word[index]; // modify it back!
        return furtherSearch;
    }
​
};
