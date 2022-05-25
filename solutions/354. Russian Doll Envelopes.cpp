class Solution {
public:
    // lis
    //https://leetcode.com/problems/russian-doll-envelopes/discuss/82796/A-Trick-to-solve-this-problem.
    // https://leetcode.com/problems/russian-doll-envelopes/discuss/82763/Java-NLogN-Solution-with-Explanation
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(begin(env),end(env),[](vector<int>& l,vector<int>& r){
            if(l[0]==r[0])
                return l[1]>r[1];
            return l[0]<r[0];
        });
        
        vector<int> lis;
        for(auto& e:env){
            auto it = lower_bound(begin(lis),end(lis),e[1]);
            if(it == end(lis))
                lis.push_back(e[1]);
            else
                *it = e[1];
        }
        return lis.size();
    }
    
    // DP n^2 : TLE
    int maxEnvelopes1(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 1);
        for (int i = 0; i < envelopes.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second)
                    dp[i]  = max(dp[i] , dp[j] + 1);
        return *max_element(dp.begin(), dp.end());
    }
};
