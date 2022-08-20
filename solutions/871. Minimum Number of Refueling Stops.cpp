class Solution {
public:
    // self
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) 
    {
        priority_queue<int> pq;
        int i=0,res=0,n=stations.size();
        while(startFuel<target) {
            while(i<n && stations[i][0]<=startFuel)
                pq.push(stations[i++][1]);
            if(pq.empty())   return -1;
            startFuel+=pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};
​
