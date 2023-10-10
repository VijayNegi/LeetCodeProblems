class Solution {
public:
    // self TLE
    int minOperations1(vector<int>& nums) {
        set<int> seen(nums.begin(),nums.end());
        int mine = numeric_limits<int>::max();
        int maxe = 1;
        int len = nums.size();
        for(auto& n:nums){
            mine = min(mine,n);
            maxe = max(maxe,n);
        }
        int maxuni=0;
        int curruni=0;
        for(int i=mine;i<=maxe;++i){
            if(seen.count(i)){
                ++curruni;
            }
            if(i-len >= mine && seen.count(i-len)){
                --curruni;
            }
            //cout<<curruni<<endl;
            maxuni = max(maxuni,curruni);
        }
        return len-maxuni;
    }
    // self
    int minOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0;
        int maxuni=1;
        int n = nums.size();
        set<int> unique(nums.begin(), nums.end());
        vector<int> newNums;
        for (int num : unique) {
            newNums.push_back(num);
        }
        for(int i=1;i<newNums.size();++i){
            while(newNums[i]-newNums[l]>=n)
                ++l;
            maxuni = max(maxuni,i-l+1);
        }
        return n-maxuni;
    }
};
