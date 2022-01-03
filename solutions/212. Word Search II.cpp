#define TRIE_LEN 26
​
struct Trie
{
    Trie* next[TRIE_LEN];
    string* s;
    Trie()
    {
        s = nullptr;
        for(int i=0;i<TRIE_LEN;++i)
            next[i] = nullptr;
    }
    
    void insert(string& s)
    {
        Trie* node = this;
        for(auto& c:s)
        {
            if(node->next[c-'a']==nullptr)
                node->next[c-'a'] = new Trie();
            node = node->next[c-'a'];
        }
        node->s = &s;
    }
};
​
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size();
        int cols = board[0].size();
        Trie root;
        
        for(auto& w:words)
            root.insert(w);
        
        vector<bool> visited(rows*cols,false);
        vector<string> result;
        function<void(Trie*,int,int)> find = [&](Trie* node, int r,int c)
        {
            if(r<0 || r == rows || c<0 || c==cols || visited[r*cols + c]==true )
                return ;
            
            char ch = board[r][c];
            ch-='a';
            if(node->next[ch])
            {
                Trie* next = node->next[ch];
                if(next->s)
                {
                    result.push_back(*(next->s));
                    next->s = nullptr;
                }
                visited[r*cols+c] = true;   
                find(next,r+1,c);
                find(next,r-1,c); 
                find(next,r,c+1);
                find(next,r,c-1);
                visited[r*cols+c] = false;
                
            }
            
            return ;
        };
        
        for(int r=0;r<rows;++r)
        {
            for(int c=0;c<cols;++c)
            {
                find(&root,r,c);
            }
        }
 
        return result;
        
    }
​
};
