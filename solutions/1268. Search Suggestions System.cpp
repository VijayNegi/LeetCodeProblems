#define TRIE_LEN 26
​
struct Trie {
    Trie* child[TRIE_LEN];
    vector<int> words;
    Trie() {
        fill(child,child+TRIE_LEN,nullptr);
    }
    void insert(string& s,int idx) {
        Trie* node = this;
        for(auto&c :s) {
            if(!node->child[c-'a'])
                node->child[c-'a'] = new Trie();
            node = node->child[c-'a'];
            if(node->words.size()<3)
                node->words.push_back(idx);
        }
    }
    vector<vector<int>> search(string s) {
        vector<vector<int>> res;
        Trie* node = this;
        for(auto&c :s) {
            if(!node->child[c-'a'])
                return res;
            node = node->child[c-'a'];
            res.push_back(node->words);
        }
        return res;
    }
};
​
class Solution {
public:
    // sort + Trie: 148ms
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(begin(products),end(products));
        Trie root;
        for(int i=0;i<products.size();++i) {
            root.insert(products[i],i);
        }
        
        auto res = root.search(searchWord);
        vector<vector<string>> result(searchWord.size());
        for(int i=0;i<res.size();++i) {
            for(auto& k:res[i])
                result[i].push_back(products[k]);
        }
        return result;
        
    }
};
