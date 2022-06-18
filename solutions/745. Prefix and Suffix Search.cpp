// hashmap : 1108ms
class WordFilter {
    unordered_map<string,int> hashmap;
public:
    WordFilter(vector<string>& words) {
        
        for(int i=0;i<words.size();i++)
        {
            int len = words[i].size();
            for(int k=0;k<=len;k++) // not equal
            {
                string pre = words[i].substr(0,k);
                for(int l=0;l<len;l++)
                {
                    string suff = words[i].substr(l,len);
                    hashmap[pre+"|"+suff] = i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return hashmap[prefix+"|"+suffix] - 1;
    }
};
​
// Trie : 563ms
/*
#define TRIE_LEN 27
​
struct Trie {
    Trie* child[TRIE_LEN];
    int hIdx;
    Trie() {
        fill(begin(child), end(child),nullptr);
        hIdx=-1;
    }
    void insert(string s,int idx) {
        Trie* node = this;
        for(auto c:s) {
           if(!node->child[c-'a'])
               node->child[c-'a'] = new Trie();
            node = node->child[c-'a'];
            node->hIdx = idx;
        }
    }
    int search(string s) {
        Trie* node = this;
        for(auto c:s) {
           if(!(node->child[c-'a']))
               return -1;
            node = node->child[c-'a'];
        }
        return node->hIdx;
    }
};
​
class WordFilter {
    Trie root;
public:
    WordFilter(vector<string>& words) {
        int idx=0;
        for(auto& s:words) {
            string suff;
            int n = s.size();
            for(int i=0;i<n;++i) {
                suff = s[n-i-1]+suff;
                root.insert(suff+"{"+s,idx);
            }
            ++idx;
        }
    }
    
    int f(string prefix, string suffix) {
        return root.search(suffix+ "{"+prefix);
    }
};
*/
/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
