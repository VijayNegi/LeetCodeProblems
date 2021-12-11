class Solution {
public:
    //contest solution , 3 ms
    // time : nlog(n)
    // space: O(n)
    vector<int> maxSubsequence1(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        vector<int> idxs(n);
        std::iota(idxs.begin(), idxs.end(), 0);
        auto comp = [&](int i,int j)
        {
          if(nums[i]>nums[j])
              return true;
            return false;
        };
        sort(begin(idxs),end(idxs),comp);
        idxs.resize(k);
        sort(begin(idxs),end(idxs));
        for(int i=0;i<k;++i)
        {
            result.push_back(nums[idxs[i]]);
        }
       return result;
    }
    // split point ,4 ms
    // time : O(n) 
    vector<int> maxSubsequence2(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        nth_element(tmp.begin(), tmp.end()-k, tmp.end());  // sort till k element
        
        int n = nums.size(), threshold = tmp[n-k], larger = 0; 
        for (auto& x : nums) 
            if (x > threshold) ++larger;    
        int equal = k - larger; 
        vector<int> ans; 
        for (auto& x : nums) 
            if (x > threshold) ans.push_back(x); 
            else if (x == threshold && equal) {
                --equal; 
                ans.push_back(x); 
            }
        return ans; 
    }
    // optimized sorting : n + klog(k) , 8 ms
    vector<int> maxSubsequence3(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); ++i)
            v.push_back({nums[i], i});
        nth_element(begin(v), begin(v) + k, end(v), greater<pair<int, int>>());
        sort(begin(v), begin(v) + k, [](const auto &a, const auto &b){ return a.second < b.second; });
        vector<int> res;
        for (int i = 0; i < k; ++i)
            res.push_back(v[i].first);
        return res;
    }
    // hash solution, 4 ms
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        vector<int> v , temp = nums;
        sort(nums.begin() , nums.end());
        unordered_map<int,int> map;
        
        for(int index = 0 ; index < k ; index ++) map[nums[nums.size() - 1- index]]++; 
        for(auto it: temp) if(map[it]-- > 0)v.push_back(it);
    return v;
    }
​
};
