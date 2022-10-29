class Solution {
public:
    // 230 ms
    int destroyTargets1(vector<int>& nums, int space) {
        
        unordered_map<int,int> mod;
        unordered_map<int,int> idx;
        int result=0;
        int id=INT_MAX;
        for(auto& n:nums){
            int m = n%space;
            mod[m]++;
            if(mod[m]==1){
                idx[m]=n;
            }
            else{
                idx[m] = min(idx[m],n);
            }
        }
        for(auto& m:mod){
            if(m.second > result )
                id = idx[m.first];
            else if(m.second >=result)
                 id = min(id,idx[m.first]);
            result = max(result,m.second);
        }
        return id;
    }
    // 163 ms
    int destroyTargets(vector<int>& nums, int space) {
        int ans = INT_MAX;
        unordered_map<int, int> mp;
        int mx = INT_MIN;
        for(auto n: nums){
            int r = n % space;                  //evaluate reminder
            mp[r]++;                               // add reminder to map
            if(mx < mp[r])  mx = mp[r];   //keep track of the max count, with same reminder
        }
        for(auto n: nums){  //scan smalest element with same riminder as of mx
            if(mx == mp[n%space])  ans = min(ans, n);
        }
        return ans;
    }
};
