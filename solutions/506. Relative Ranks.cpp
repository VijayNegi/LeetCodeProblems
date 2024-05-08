class Solution {
public:
    vector<string> findRelativeRanks1(vector<int>& nums) {
        priority_queue<pair<int,int> > pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(make_pair(nums[i],i));
        }
        vector<string> res(nums.size(),"");
        int count = 1;
        for (int i=0; i<nums.size(); i++) {
            auto p = pq.top();
            pq.pop();
            if (i==0) res[p.second] = "Gold Medal";
            else if (i==1) res[p.second] = "Silver Medal";
            else if (i==2) res[p.second] = "Bronze Medal";
            else res[p.second] = to_string(i+1);
        }
        return res;
    }
    vector<string> findRelativeRanks(vector<int>& nums) {
      vector<short> idx(nums.size());
      vector<string> res(nums.size());
      iota(begin(idx), end(idx), 0);
      sort(begin(idx), end(idx), [&nums](int i, int j) { return nums[i] > nums[j]; });
      for (auto i = 0; i < nums.size(); ++i)
        res[idx[i]] = i == 0 ? "Gold Medal" : i == 1 ? "Silver Medal" : i == 2 ? "Bronze Medal" : to_string(i + 1);
      return res;
    }
};
