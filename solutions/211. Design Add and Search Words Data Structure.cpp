#define TRIE_LEN 26
​
struct Trie
{
    Trie* next[TRIE_LEN];
    bool end;
    Trie()
    {
        fill(next,next+ TRIE_LEN, nullptr);
        end = false;
    }
    
    void add(string s)
    {
        Trie* curr = this;
        
        for(auto c:s)
        {
            int idx = c-'a';
            if(!(curr->next[idx]))
                curr->next[idx] = new Trie();
            curr = curr->next[idx];
        }
        curr->end = true;
    }
    
    bool search(string& s)
    {
        return search(s,0);
    }
    
    bool search(string& s, int idx)
    {
        if(idx == s.size())
            return end;
        
        if(s[idx]!='.')
        {
            int i = s[idx]-'a';
            if(next[i])
               return next[i]->search(s,idx+1);
        }
        else
        {
            for(int i=0;i<TRIE_LEN;++i)
            {
                if(next[i] && next[i]->search(s, idx+1))
                    return true;
            }
        }
        return false;
    }
};
​
class WordDictionary {
    Trie mDict;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mDict.add(word);
    }
    
    bool search(string word) {
        return mDict.search(word);
    }
};
​
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
