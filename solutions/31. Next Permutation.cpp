class Solution {
public:
    // 7 ms
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        for(;i>=0;--i)
            if(nums[i+1]>nums[i])
            {
                int j=i+1;
                for(;j<n;++j)
                    if(nums[j]<=nums[i])
                        break;
                swap(nums[i],nums[j-1]);
                break;
            }
        reverse(begin(nums)+i+1,end(nums));
    }
    // 3 ms
    void nextPermutation2(vector<int>& nums) {
      std::next_permutation(nums.begin(), nums.end());
    }
    // some more STL
    void nextPermutation3(vector<int>& nums) {
      auto dest = std::is_sorted_until(nums.rbegin(), nums.rend());
      if (dest != nums.rend()) {
        auto target = std::upper_bound(nums.rbegin(), dest, *dest);
        std::iter_swap(dest, target);
      }
      std::reverse(nums.rbegin(), dest);
    }
​
};
