class Solution {
public:
    
    bool detectCapitalUse(string word) {
        int n = word.size();
        int count=0;
        for(auto& c:word)
            if(toupper(c)==c)
                ++count;
        if(count==0 || count==n || (count==1 && toupper(word[0]) == word[0]))
            return true;
        return false;
    }
    bool detectCapitalUse1(string word) {
        int n = word.size();
        int caps = 0;
        for(int i=0;i<n;++i)
        {
            if(isupper(word[i]))
                ++caps;
            
            if(caps != i+1 && isupper(word[i]))
                return false;
            if(caps > 1 && islower(word[i]))
                return false;
        }
        
        return true;
    }
    //another way
    bool detectCapitalUse2(string word) {
        int cnt=0;
        int loc;
        for(int i=0;i<word.length();i++){
            if(word[i]>='A' && word[i]<='Z'){
                cnt++;
                loc = i;
            }
        }
        if(cnt == word.length() || cnt == 0 || (cnt==1 && loc==0))
            return true;
        return false;
    }
    //another
    bool detectCapitalUse3(string word) {
        for(int i = 1; i < word.size(); i++){
            if(isupper(word[1]) != isupper(word[i]) || islower(word[0]) && isupper(word[i])) 
                return false;
        }        
        return true;
    }
};
