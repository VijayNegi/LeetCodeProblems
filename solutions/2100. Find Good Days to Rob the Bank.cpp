class Solution {
public:
    //contest
    vector<int> goodDaysToRobBank1(vector<int>& s, int time) {
        int n = s.size();
        vector<int> result;
        //checks;
        if(time == 0)
        {
            result = vector<int>(n);
            std::iota(result.begin(), result.end(), 0);
            return result;
        }
        else if(n<2*time)
            return result;
        
        vector<bool> nondec(n,false);
        int streak = 0;
        for(int i=n-2;i>=0;--i)
        {
            if(s[i]<=s[i+1])
                ++streak;
            else
                streak=0;
            if(streak>=time)
                nondec[i] = true;
        }
        streak = 0;
        
        for(int i=1;i<n;++i)
        {
            if(s[i]<=s[i-1])
                ++streak;
            else
                streak = 0;
            if(streak>=time && nondec[i])
                result.push_back(i);
            
        }
        return result;
    }
    // cleanup
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size(); 
        vector<int> suffix(n); 
        for (int i = n-2; i >= 0; --i) 
            if (security[i] <= security[i+1]) suffix[i] = suffix[i+1] + 1; 
        
        vector<int> ans; 
        int prefix = 0; 
        for (int i = 0; i < n-time; ++i) {
            if (i && security[i-1] >= security[i]) ++prefix; 
            else prefix = 0; 
            if (prefix >= time && suffix[i] >= time) ans.push_back(i); 
        }
        return ans; 
    }
};
