class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        unordered_map<int,int> modSeen;
        int res=0;
        for(int i=0;i<n;++i)
        {
            int t = time[i]%60;
            int c = 60-t;
            if(c==60)
                c=0;
            
            if( modSeen.count(c))
            {
                res += modSeen[c];
            }
            
            modSeen[t]++;
        }
        return res;
    }
};
