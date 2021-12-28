/*
Solution with recurtion : 112 ms
#define TRIE_LEN 26
class Trie {
    bool end;
    vector<Trie*> child;
public:
    Trie() {
        end= false;
        child = vector<Trie*>(TRIE_LEN,nullptr);
    }
    
    void insert(string word) {
        if(child[word[0]-'a']==nullptr)
        {
            child[word[0]-'a'] = new Trie();
        }
        child[word[0]-'a']->insert(word,1);
    }
    
    bool search(string word) {
        if(child[word[0]-'a']==nullptr)
            return false;
        return child[word[0]-'a']->search(word,1);
    }
    
    bool startsWith(string prefix) {
        return startsWith(prefix,0);
        
    }
private:
    void insert(string s,int idx)
    {
        if(idx>= s.size())
        {
            end = true;
            return;
        }
        int i = s[idx]-'a';
        if(child[i]==nullptr)
            child[i] = new Trie();
        child[i]->insert(s,idx+1);
    }
    bool search(string s, int idx)
    {
        if(idx==s.size())
            return end;
        int i = s[idx]-'a';
        if(child[i]==nullptr)
            return false;
        return child[i]->search(s,idx+1);
    }
    bool startsWith(string s,int idx)
    {
        if(s.size()== idx)
            return true;
        int i = s[idx]-'a';
        if(child[i]==nullptr)
            return false;
        return child[i]->startsWith(s,idx+1);
    }
    
    
};
*/
// Solution: iterative 52 ms
class Trie {
public:
    Trie() {}
​
    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (!node->next[ch]) { node->next[ch] = new Trie(); }
            node = node->next[ch];
        }
        node->isword = true;
    }
​
    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (!node->next[ch]) { return false; }
            node = node->next[ch];
        }
        return node->isword;
    }
​
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (!node->next[ch]) { return false; }
            node = node->next[ch];
        }
        return true;
    }
​
