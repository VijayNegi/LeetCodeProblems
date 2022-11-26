            maxProfit[stTime] = p;
            return p;
        };
        return dfs(0,0);
    }
    // https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409009/JavaC%2B%2BPython-DP-Solution
    // Bottom up : 254 ms
    int jobScheduling2(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    }
    //https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409188/C++-with-picture/418565
    // Bottom up : 276 ms
    int jobScheduling3(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int, int> dp;
        vector<vector<int>> jobs;
        for (int i = 0; i < startTime.size(); i++) {
            jobs.push_back(vector<int>{startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        int maxT = 0;
        for (auto job : jobs) {
            auto it = dp.lower_bound(job[1]);
            int pre = (it == dp.end()) ? 0 : it->second;
            maxT = max(maxT, job[2] + pre);
            dp[job[0]] = maxT;
        }
        
        return maxT;
    }
};
