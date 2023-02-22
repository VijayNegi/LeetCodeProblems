class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        function<bool(int)> checkCapacity = [&](int capacity){
            int res=1;
            int sum=0;
            for(auto& w:weights){
                
                sum += w;
                if(sum>capacity){
                    ++res;
                    if(w>capacity) return false;
                    sum = w;
                }
            }
            return res<= days;
        };
        
        int l=0,r= INT_MAX;
        while(l<r){
            int mid = l + (r-l)/2;
            if(checkCapacity(mid))
                r = mid;
            else
                l = mid+1;
        }
        return r;
    }
    
};
