            string suf = words[i];
            for(int j=0;j<=words[i].size();++j)
            {
                
                if(j>0 && checkPalindrome1(pre) && m.find(suf)!=m.end() && m[suf]!=i)
                    result.push_back({m[suf],i});
                if(checkPalindrome1(suf) && m.find(pre)!=m.end() && m[pre]!=i)
                    result.push_back({i,m[pre]});
                if(j<words[i].size())
                {
                    pre += words[i][j];
                    suf.erase(0,1);
                }
            }
        }
        return result;
    }
    bool checkPalindrome1(const string& ss)
    {
        int s=-1,e=ss.size();
        while(++s<=--e)
            if(ss[s]!=ss[e])
                return false;
        return true;
    }
};
​
#else
//**************************************************************************************************
//   TRIE solution from
// https://leetcode.com/problems/palindrome-pairs/discuss/79195/O(n-*-k2)-java-solution-with-Trie-structure/84087
// TLE BTW
struct Node {
    unordered_set<int> strIds;
    vector<Node*> nexts;
    int index;
    Node(): nexts(vector<Node*>(26, NULL)), index(-1) {}
};
​
class Trie {
public:
    Trie(vector<string>& words) {
        root = new Node();
        for(int i = 0; i < words.size(); i++) {
            insert(words[i], i);
        }
    }
    
    void insert(string& str, int index) {
        auto run = root;
        for(int i = str.size()-1; i >= 0; i--) {
            char c = str[i];
            if(run->nexts[c-'a'] == NULL) run->nexts[c-'a'] = new Node();
            if(isPalindrome(str, 0, i)) run->strIds.insert(index);
            run = run->nexts[c-'a'];
        }
        run->index = index;
