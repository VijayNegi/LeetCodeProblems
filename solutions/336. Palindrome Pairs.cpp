//1st case : prefix of String a + latter part of a(palindrome) + whole String b = new palindrome.
//2nd case : whole String a + prefix of String b(palindrome) + suffix of String b = new palindrome.
#if 0
class Solution {
public:
    // 1579 ms
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int> smap;
        int n = words.size();
        for(int i=0;i<n;++i)
        {
            string s = words[i];
            reverse(begin(s),end(s));
            smap[s] = i;
        }
            
        vector<vector<int>> result;
        for(int i=0;i<n;++i)
        {
            string& s = words[i];
            int k = s.size();
            string pre = "";
            string suf = s;
            for(int j=0;j<=k;++j)
            {
                if(j>0 && isPalindrome(s,0,j-1) ) 
                {
                    //string str = s.substr(j); //suffix
                    if(smap.find(suf) != smap.end() && smap[suf] != i)
                        result.push_back({smap[suf],i});
                }
                if(isPalindrome(s,j,k-1))
                {
                    //string str = s.substr(0,j);
                    if(smap.find(pre) != smap.end() && smap[pre] != i)
                       result.push_back({i,smap[pre]});
                }
                if(j<k)
                {
                    pre += words[i][j];
                    suf.erase(0,1);
                }
            }
        }
        return result;
    }
    
    bool isPalindrome(string& s, int l,int r)
    {
        while(l<r)
            if(s[l++]!=s[r--])
                return false;
        return true;
    }
    // 1875 ms
    vector<vector<int>> palindromePairs2(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string,int> m;
        for(int i=0;i<words.size();++i)
        {
            m[string(words[i].rbegin(),words[i].rend())] = i;
        }
        for(int i=0;i<words.size();++i)
        {
            string pre = "";
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

#else
//**************************************************************************************************
//   TRIE solution from
// https://leetcode.com/problems/palindrome-pairs/discuss/79195/O(n-*-k2)-java-solution-with-Trie-structure/84087
// TLE BTW
struct Node {
    unordered_set<int> strIds;
    vector<Node*> nexts;
    int index;
    Node(): nexts(vector<Node*>(26, NULL)), index(-1) {}
};

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
        run->strIds.insert(index);
    }
    
    void search(string& str, int index, vector<vector<int> >& result) {
        auto run = root;
        for(int i = 0; i < str.size(); i++) {
            char c = str[i];
            if(run->index >= 0 && run->index != index && isPalindrome(str, i, str.size()-1)) 
                result.push_back({index, run->index});
            if(run->nexts[c-'a'] == NULL) return;
            run = run->nexts[c-'a'];
        }
        for(int id: run->strIds) {
            if(id == index) continue;
            result.push_back({index, id});   
        }      
    }
    
private:
    Node* root;
    
    bool isPalindrome(string& str, int l, int r) {
        while(l < r) {
            if(str[l] != str[r]) return false;
            l++; r--;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie trie(words);
        vector<vector<int> > result;
        for(int i = 0; i < words.size(); i++) {
            trie.search(words[i], i, result);
        }
        return result;
    }
};

#endif
