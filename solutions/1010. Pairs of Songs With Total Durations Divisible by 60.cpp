class Solution {
public:
    int numPairsDivisibleBy60_1(vector<int>& time) {
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
    // more clean code
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> c(60);
        int res = 0;
        for (int t : time) {
            res += c[(600 - t) % 60];
            c[t % 60] += 1;
        }
        return res;
    }
};
