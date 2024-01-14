class Solution {
public:
    vector<int> sums;
    Solution(vector<int>& w) {
        sums.reserve(w.size());
        int temp=0;
        for(int i=0;i<w.size();i++)
        {
            temp+=w[i];
            sums.push_back(temp);
        }
    }
    
    int pickIndex() {
        int r = rand()%(sums.back());
        auto it=upper_bound(sums.begin(),sums.end(),r);
        return distance(sums.begin(),it);
    }
};
​
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
