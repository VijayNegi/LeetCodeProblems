class Solution {
public:
    string removeDuplicateLetters(string s) {
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
};
