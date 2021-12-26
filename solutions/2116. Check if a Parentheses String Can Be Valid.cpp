class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n & 1)
            return false;
        
        int cOpen = 0;
        int cClose = 0;
        int cUnlocked = 0;
        for(int i=0;i<n;++i)
        {
            
            if(locked[i]=='1')
            {
                if(s[i]=='(')
                    ++cOpen;
                else
                    ++cClose;
                
                // check if this could be valid
                if(cClose > (cOpen + cUnlocked))
                    return false;
            }
            else
                ++cUnlocked;
        }
        
        cOpen = 0;
        cClose = 0;
        cUnlocked = 0;
        for(int i=n-1;i>=0;--i)
        {
           
            if(locked[i]=='1')
            {
                if(s[i]=='(')
                    ++cOpen;
                else
                    ++cClose;
                
                // check if this could be valid
                if(cOpen > (cClose + cUnlocked))
                    return false;
            }
            else
                ++cUnlocked;
        }
        return true;
        
    }
};
