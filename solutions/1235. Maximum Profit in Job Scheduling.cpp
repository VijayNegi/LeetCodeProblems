class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        map<int,int> maxProfit; // startTime, profit
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i=0;i<n;++i){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        function<int(int,int)> dfs = [&](int idx,int stTime){
            if(idx>=n)
                return 0;
            if(maxProfit.count(stTime))
                return maxProfit[stTime];
            int p = 0;
            for(int i=idx;i<n;++i){
                if(jobs[i][0]>=stTime){
                    auto l = maxProfit.lower_bound(stTime);
                    if(l != maxProfit.end() && l->first <= jobs[i][0]){
                        p = max(p, l->second);
                        break;
                    }
                    else{
                        p = max(p, dfs(i+1, jobs[i][1]) + jobs[i][2]);
                    }
                    
                }
                    
            }
            maxProfit[stTime] = p;
            return p;
        };
        return dfs(0,0);
    }
};
