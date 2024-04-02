class Solution {
public:
    bool isIsomorphic1(string s, string t) {
        vector<char> mapS(256,' ');
        vector<char> mapT(256,' ');
        
        for(int i=0;i<s.size();++i)
        {
            if(mapS[s[i]]!= ' ' &&  mapS[s[i]] != t[i])
                return false;
            if(mapT[t[i]]!= ' ' && mapT[t[i]] != s[i])
                return false;
            if(mapS[s[i]]==' ')
            {
                mapS[s[i]] = t[i]; 
                mapT[t[i]] = s[i]; 
            }
        }
        
        return true;
    }
    //save location ease conditions
    bool isIsomorphic(string s, string t) {
        vector<int> mapS(256,-1);
        vector<int> mapT(256,-1);
        for(int i=0;i<s.size();++i)
        {
            if(mapS[s[i]] != mapT[t[i]])
                return false;
            mapS[s[i]] = i;
            mapT[t[i]] = i;
                
        }
        return true;
    }
};
