class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
            return false;
        vector<int> diff;
        vector<int> count(26,0);
​
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=B[i])
                diff.push_back(i);
            count[A[i] - 'a']++;
        }
        if(diff.size()>2 || diff.size() == 1) // will handle 0 case differently
            return false;
        if(diff.empty())
        {
            for(const auto& a : count)
                if(a>1) return true;
        }
        else if(A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]])
            return true;
        
        return false;
        
    }
};
