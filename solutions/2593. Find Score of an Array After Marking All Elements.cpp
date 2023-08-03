class Solution {
public:
    // https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/discuss/3312018/Index-Array
    long long findScore1(vector<int>& n) {
        long long score = 0, sz = n.size();
        vector<int> id(sz);
        iota(begin(id), end(id), 0);
        stable_sort(begin(id), end(id), [&](int i, int j){ return n[i] < n[j]; });
        for (int i : id)
            if (n[i]) {
                score += n[i];
                n[i] = n[min((int)sz - 1, i + 1)] = n[max(0, i - 1)] = 0;            
            }
        return score;
    }
    //https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/discuss/3312206/Using-ordered-set-oror-Very-Simple-and-Easy-to-Understand-Solution
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        set<pair<int, int>> st;
        for(int i = 0; i < nums.size(); ++i){ st.insert({nums[i], i}); }
        for(auto s: st){
            if(nums[s.second]) {
                nums[s.second] = 0;
                if(s.second - 1 >= 0) nums[s.second - 1] = 0;
                if(s.second + 1 < nums.size()) nums[s.second + 1] = 0;
                ans += s.first;
            }
        }
        return ans;
    }
};
