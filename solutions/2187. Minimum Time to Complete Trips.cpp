class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        function<bool(long)> tripsInTime = [&](long t){
            long count=0;
            for(auto& b:time){
                count += t/b;
                if(count>=totalTrips) return false;
            }
            return true;
        };
        long l=0,h=1e15;
        while(l<h){
            long mid = l+ (h-l)/2;
            bool isLess = tripsInTime(mid);
            if(isLess)
                l= mid+1;
            else
                h = mid;
        }
        return l;
    }
};
