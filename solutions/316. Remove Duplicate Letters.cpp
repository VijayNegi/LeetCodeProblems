class Solution {
public:
    string removeDuplicateLetters1(string s) {
        vector<int> count(27,0);
        vector<bool> visited(27,false);
        
        for(char c: s)
         count[c-'a']++;
        string result("");
        for(char c:s)
        {
            count[c-'a']--;
            
            if(visited[c-'a'])
                continue;
            
            while(!result.empty() && result.back()>c && count[ result.back() - 'a']>0)
            {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            result +=c;
            visited[c-'a'] = true; 
        }
        
        return result;
    }
    // instead of count we can also use last index
    string removeDuplicateLetters(string s) {
        vector<int> last(27,0);
        vector<bool> visited(27,false);
        for(int i=0;i<s.size();++i)
            last[s[i]-'a'] = i;
        string result("");
        for(int i=0;i<s.size();++i)
        {
            char c = s[i];
            if(visited[c-'a'])
                continue;
            
            while(!result.empty() && result.back()>c && last[ result.back() - 'a']>i)
            {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            result +=c;
            visited[c-'a'] = true; 
        }
        
        return result;
    }
};
