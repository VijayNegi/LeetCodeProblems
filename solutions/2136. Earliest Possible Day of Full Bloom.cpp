class Solution {
public:
    // greedy : 557 ms
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();
        vector<pair<int,int>> gp(n);
        for(int i=0;i<n;++i)
            gp.push_back({growTime[i],plantTime[i]});
        sort(begin(gp),end(gp),[](pair<int,int> a,pair<int,int> b){ return (a.first > b.first);  });
        
        int endTime=0;
        int plantEnd = 0;
        for(int i=0;i<n;++i)
        {
            auto [g,p] = gp[i];
            plantEnd += p;
            endTime = max(endTime, plantEnd + g);
        }
        return endTime;
    }
};
