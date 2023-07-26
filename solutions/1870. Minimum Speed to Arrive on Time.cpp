class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int n = dist.size();
        if(hour <= n-1) return -1;
        int l=1,r =1e7;
        function<bool(int)> canReach = [&](int s){
            double time=0;
            for(auto& k:dist){
                time = ceil(time);
                time += (double)k/s;
            }
            return time <= hour;
        };
        
        while(l<r){
            int m = (l+r)/2;
            if(canReach(m)){
                r = m;
            }
            else
                l = m+1;
        }
        return l;
    }
};
