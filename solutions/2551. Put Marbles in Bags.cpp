class Solution {
public:
    // TLE
    long long putMarbles1(vector<int>& weights, int k) {
        int n = weights.size();
        vector<vector<vector<long>>> dp(n,vector<vector<long>>(k+1,vector<long>(2,-1))); // excedes memory limit
        unordered_map<int,unordered_map<int,long>> dp_min;
        unordered_map<int,unordered_map<int,long>> dp_max;
        
        function<void(int,int)> dfs = [&](int idx,int bags){
            //cout<<idx<<" "<<bags<<endl;
            if(idx==n) return;
            if(dp_min[idx][bags] != 0) return;
            long score_min = numeric_limits<long>::max();
            long score_max = numeric_limits<long>::min();
            if(bags == 1){
                dp_min[idx][bags] = weights[idx]+ weights[n-1];
                dp_max[idx][bags] =  dp_min[idx][bags];
                return;
            }
            if(bags == n-idx){
                dfs(idx+1,bags-1);
                dp_min[idx][bags] = dp_max[idx][bags]= weights[idx]+weights[idx];
                if(idx != n-1){
                    dp_min[idx][bags] += dp_min[idx+1][bags-1];
                    dp_max[idx][bags] += dp_max[idx+1][bags-1];
                }  
                return;
            }
            for(int i=idx;i<=n-bags;++i){
                dfs(i+1,bags-1);
                score_min = min(score_min, weights[idx]+ weights[i]+ dp_min[i+1][bags-1] );
                score_max = max(score_max, weights[idx]+ weights[i]+ dp_max[i+1][bags-1] );
            }
            dp_min[idx][bags]= score_min;
            dp_max[idx][bags] = score_max;
        };
        dfs(0,k);
        //cout<<dp[0][k][1]<<"  "<<dp[0][k][0]<<endl;
        return dp_max[0][k] - dp_min[0][k];
    }
    // greedy , 198ms
    long long putMarbles(vector<int>& weights, int k) {
        // We collect and sort the value of all n - 1 pairs.
        int n = weights.size();
        vector<int> pairWeights(n - 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            pairWeights[i] += weights[i] + weights[i + 1];
        }
        sort(pairWeights.begin(), pairWeights.end());
        // Get the difference between the largest k - 1 values and the 
        // smallest k - 1 values.
        long long answer = 0;
        for (int i = 0; i < k - 1; ++i) {
            answer += pairWeights[n - 2 - i] - pairWeights[i];
        }
​
        return answer;
    }
};
