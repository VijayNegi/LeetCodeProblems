class Solution {
public:
    // contest: 660 ms // missed the last constraint i.e. no char will repeat in start and target
    int wordCount1(vector<string>& startWords, vector<string>& targetWords) {
        int sn = startWords.size();
        int tn = targetWords.size();
        vector<vector<int>> sh(sn);
        vector<vector<int>> th(tn);
        vector<vector<int>> szmap(27);
        unordered_set<string> hmap;
        int i=0;
        for(auto& s:startWords)
        {
            szmap[s.size()].push_back(i);
            sh[i++] = getHist(s);
            hmap.insert(getstring(sh[i-1]));
            //++i;
        }
            
        i=0;
         for(auto& s:targetWords)
            th[i++] = getHist(s);
        int res=0;
        for(i=0;i<tn;++i)
        {
            int sz = targetWords[i].size();
            // gen combi
            vector<int> v = th[i];
            for(int i=0;i<26;++i)
            {
                if( v[i] == 1 )
                {
                    v[i]--;
                    string s = getstring(v);
                    
                    v[i]++;
                    if(hmap.count(s))
                    {
                        ++res;
                        break;
                    }
                        
                }
            }
        }
        return res;
    }
    
    vector<int> getHist(string& s)
    {
        vector<int> hist(26,0);
        for(auto a:s)
            hist[a-'a']++;
        return hist;
    }
    bool compHist(vector<int> a, vector<int> b)
    {
        for(int i=0;i<26;++i)
        {
            if(a[i] !=0 && a[i] != b[i])
                return false;
        }
        return true;
    }
    string getstring(vector<int>& a)
    {
        string s;
        for(int i=0;i<26;++i)
            if(a[i])
                s.append(a[i],'a'+i);
        return s;
    }
    //----------------------------
    // considering the constraint : 268 ms
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> hmap;
        for(auto& s:startWords)
            hmap.insert(convertInt(s));
        int res=0;
        for(auto& t:targetWords)
        {
            // generate combinations
            int v = convertInt(t);
            for(int i=0;i<26;++i)
            {
                if(v !=  (v & ~(1<<i)) )
                {
                    int vt = (v & ~(1<<i));
                    if(hmap.count(vt))
                    {
                        ++res;
                        break;
                    }
                        
                }
            }
        }
        return res;
    }
    
    int convertInt(string s)
    {
        int res =0;
        for(auto& c:s)
            res |= 1<<(c-'a');
        return res;
    }
    
};
