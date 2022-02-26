class Solution {
public:
    vector<int> prefix_func(string s)
    {
        int n = s.size();
        vector<int> pi(n,0);
        int k=0;
        for(int i=1;i<n;++i)
        {
            while(k>0 && s[k]!= s[i])
                k = pi[k-1];
            if(s[k]==s[i])
                ++k;
            pi[i] = k;
        }
        return pi;
    }
    int search_word(string p,string t)
    {
        int n = t.size();
        vector<int> pi= prefix_func(p) ;
        int k=0;
        int index = 0;
        for(int i=0;i<n;++i)
        {
            if(t[i]==' ')
                ++index;
            while(k>0 && p[k]!= t[i])
                k = pi[k-1];
            if(p[k]==t[i])
                ++k;
            if(k==p.size())
                return index;
            
        }
        return -1;
    }
    // KMP 0 ms
    int isPrefixOfWord1(string sentence, string searchWord) {
        return search_word(" "+searchWord," "+sentence);
    }
    
    // std search 0 ms
    int isPrefixOfWord2(string sentence, string searchWord) {
        auto sent = " " + sentence, word = " " + searchWord;
        auto pos = sent.find(word);
        if (pos != string::npos)
            return count(begin(sent), begin(sent) + pos + 1, ' ');
        return -1;
    }
    // KMP type as our work only start with space
    int isPrefixOfWord(string sentence, string searchWord) {
        auto sent = " " + sentence, word = " " + searchWord;
        int word_cnt = 0, j = 0;
        for (auto i = 0; i < sent.size() && j < word.size(); ++i) {
            word_cnt += sent[i] == ' ';
            if (sent[i] == word[j])
                ++j;
            else
                j = sent[i] == word[0] ? 1 : 0;
        }
        return j == word.size() ? word_cnt : -1;
    }
};
