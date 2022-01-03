            {
                curr->end = true;
                break;
            }
            char c = w[idx];
            c -='a';
            if(!curr->next[c])
                curr->next[c] = new Trie();
            ++idx;
            curr = curr->next[c];
            
        }
    }
    
    bool search(string& w)
    {
        return search(w,0);
    }
    
private:
    bool search(string& w,int idx)
    {
        if(idx == w.size())
            return end;
        char c = w[idx];
        if( c == '.' )
        {
            for(int i = 0; i< TRIE_LEN; ++i)
            {
                if(next[i] && next[i]->search(w,idx+1))
                        return true;
            }
        }
        else
        {
            c -= 'a';
            if(next[c] && next[c]->search(w,idx+1))
                return true;
        }
        
        return false;
    }
};
​
class WordDictionary {
    Trie Dict;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Dict.insert(word);
    }
    
    bool search(string word) {
        return Dict.search(word);
    }
};
​
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
